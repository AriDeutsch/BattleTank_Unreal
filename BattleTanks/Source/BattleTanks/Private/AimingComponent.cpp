// Fill out your copyright notice in the Description page of Project Settings.


#include "AimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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
	if (!MyTanksBarrel)return;
	FVector OutLaunchVelocity;
	if (UGameplayStatics::SuggestProjectileVelocity(MyTanksBarrel, OutLaunchVelocity, MyTanksBarrel->GetSocketLocation(FName("Missile Origin")), Target, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		FVector LaunchDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(LaunchDirection);
	}
}



void UAimingComponent::MoveBarrelTowards(FVector Direction)
{
	FRotator BarrelRotation = MyTanksBarrel->GetForwardVector().Rotation();
	FRotator DeltaRotation = Direction.Rotation() - BarrelRotation;
	UE_LOG(LogTemp, Warning, TEXT("BarrelRotation %s"), *DeltaRotation.ToString())

	MyTanksBarrel->Elevate(5);
}

void UAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	MyTanksBarrel = BarrelToSet;
}

