// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//RelativeSpeed = -1 => -ve max speed. RelativeSpeed = 1 => +ve max speed. 0 => 0 speed
	void Rotate(float RelativeSpeed);

private:
	//Angular speed of barrel pitch
	UPROPERTY(EditAnywhere, Category = Setup)
	float DegreesPerSecond = 40;
};
