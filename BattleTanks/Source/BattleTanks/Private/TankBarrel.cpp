// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	//UE_LOG(LogTemp, Warning, TEXT("%f: Elevating at speed %f"), GetWorld()->GetTimeSeconds(), RelativeSpeed)

	float PitchChange = RelativeSpeed * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewPitch = RelativeRotation.Pitch + PitchChange;
	NewPitch = FMath::Clamp<float>(NewPitch, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(NewPitch, 0, 0));
}

