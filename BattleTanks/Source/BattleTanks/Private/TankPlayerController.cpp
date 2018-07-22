// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* thisTank = GetControlledTank();
	if (thisTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Player possessing %s"), *thisTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not possessing a tank"))
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


