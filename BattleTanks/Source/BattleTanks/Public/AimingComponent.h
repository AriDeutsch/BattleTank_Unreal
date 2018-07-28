// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAtTarget(FVector Target, float LaunchSpeed);

	void SetBarrelReference(UStaticMeshComponent* BarrelReference);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	int i = 0;
	int successes = 0;
	UStaticMeshComponent * MyTanksBarrel = nullptr;
	
};
