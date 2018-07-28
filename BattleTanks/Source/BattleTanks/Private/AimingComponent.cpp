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

void UAimingComponent::AimAtTarget(FVector Target, float LaunchSpeed)
{
	if (!MyTanksBarrel)return;


	FVector OutLaunchVelocity;

	if (UGameplayStatics::SuggestProjectileVelocity(MyTanksBarrel, OutLaunchVelocity, MyTanksBarrel->GetSocketLocation(FName("Missile Origin")), Target, LaunchSpeed, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		FVector LaunchDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("TICK %d: !!!!!SUCCESSFUL ATTEMPT!!!!! for %s"), i, *GetOwner()->GetName())
		++successes;
		UE_LOG(LogTemp, Warning, TEXT("%s aiming towards %s"), *GetOwner()->GetName(), *LaunchDirection.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TICK %d: !!!!!FAILED ATTEMPT!!!!! for %s"), i, *GetOwner()->GetName())
		UE_LOG(LogTemp, Warning, TEXT("WorldObject: %s"), *MyTanksBarrel->GetName())
		UE_LOG(LogTemp, Warning, TEXT("launch velocity: %s"), *OutLaunchVelocity.ToString())
		UE_LOG(LogTemp, Warning, TEXT("launch direction: %s"), *OutLaunchVelocity.GetSafeNormal().ToString())
		UE_LOG(LogTemp, Warning, TEXT("socket location: %s"), *MyTanksBarrel->GetSocketLocation(FName("Missile Origin")).ToString())
		UE_LOG(LogTemp, Warning, TEXT("target: %s"), *Target.ToString())
		UE_LOG(LogTemp, Warning, TEXT("launch speed: %f"), LaunchSpeed)
	}
	UE_LOG(LogTemp, Warning, TEXT("cumulative successes: %d"), successes)
	++i;
}

void UAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelReference)
{
	MyTanksBarrel = BarrelReference;
}

