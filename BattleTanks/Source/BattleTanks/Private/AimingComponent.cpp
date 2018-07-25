// Fill out your copyright notice in the Description page of Project Settings.


#include "AimingComponent.h"


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

void UAimingComponent::AimAtTarget(FVector Target, float LaunchSpeed) const
{
	if (!MyTanksBarrel)return;

	FVector OutLaunchVelocity;

	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, MyTanksBarrel->GetSocketLocation(FName("Missile Origin")), Target, LaunchSpeed,0,0,ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		FVector LaunchDirection = OutLaunchVelocity / LaunchSpeed;
		UE_LOG(LogTemp, Warning, TEXT("%s aiming towards %s"), *GetOwner()->GetName(), *OutLaunchVelocity.ToString());
	}


}

void UAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelReference)
{
	MyTanksBarrel = BarrelReference;
}

