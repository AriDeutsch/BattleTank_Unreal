// Fill out your copyright notice in the Description page of Project Settings.

#include "AimingComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; // TODO Does this need to tick?

	// ...
}


// Called when the game starts
void UAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimingComponent::AimAtTarget(FVector Target, float LaunchSpeed)
{
	if (!MyTanksBarrel||!MyTanksTurret)return;
	FVector OutLaunchVelocity;
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, MyTanksBarrel->GetSocketLocation(FName("Missile Origin")), Target, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		//UE_LOG(LogTemp,Warning,TEXT("%f: SUCCESS"), GetWorld()->GetTimeSeconds())
		FVector LaunchDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(LaunchDirection);
		MoveTurretTowards(LaunchDirection);
	}
	else{ /*UE_LOG(LogTemp, Warning, TEXT("%f: FAIL"), GetWorld()->GetTimeSeconds())*/ }
}



void UAimingComponent::MoveBarrelTowards(FVector Direction)
{
	FRotator BarrelRotation = MyTanksBarrel->GetForwardVector().Rotation();
	FRotator DeltaRotation = Direction.Rotation() - BarrelRotation;
	MyTanksBarrel->Elevate(DeltaRotation.Pitch);
}

void UAimingComponent::MoveTurretTowards(FVector Direction)
{
	FRotator TurretRotation = MyTanksTurret->GetForwardVector().Rotation();
	FRotator DeltaRotation = Direction.Rotation() - TurretRotation;
	MyTanksTurret->Rotate(DeltaRotation.Yaw);
}

void UAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	MyTanksBarrel = BarrelToSet;
}

void UAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	MyTanksTurret = TurretToSet;
}

