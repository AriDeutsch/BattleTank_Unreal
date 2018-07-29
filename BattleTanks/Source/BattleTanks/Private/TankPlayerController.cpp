// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Public/Tank.h"

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
	AimAtCrosshairs();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshairs()
{
	if (!GetControlledTank())return;

	//We will line trace out from the crosshairs world location, and if it hits something, HitLocation will
	//be the info container for the location of where the line trace is hitting that thing
	FVector HitLocation;
	if (GetCrosshairsHitLocation(HitLocation))
	{
		GetControlledTank()->AimAtTarget(HitLocation);
	}
}

bool ATankPlayerController::GetCrosshairsHitLocation(FVector& OutHitLocation) const
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	
	//Out parameters for deproject function
	FVector CrosshairsWorldLocation; 
	FVector CameraRotation;
	if (DeprojectScreenPositionToWorld(CrosshairsScreenRatioX*ViewPortSizeX, CrosshairsScreenRatioY*ViewPortSizeY, CrosshairsWorldLocation, CameraRotation))
	{
		FVector LineTraceEnd = CrosshairsWorldLocation + FireRange * CameraRotation;

		FHitResult HitObject;//OutHitLocation will be updated by function provided HitObject is not null

		if (GetWorld()->LineTraceSingleByChannel(HitObject, CrosshairsWorldLocation, LineTraceEnd, ECC_Visibility))
		{
			OutHitLocation = HitObject.Location;
			return true;
		}
		OutHitLocation = FVector(0);
		return false; //Line trace did not hit anything
	}
	return false;//Deproject didn't work
	
}


