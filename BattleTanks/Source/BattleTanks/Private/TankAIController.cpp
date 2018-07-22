// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* MyControlledTank = GetControlledTank();
	if (MyControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possessing %s"), *MyControlledTank->GetName())
		
		ATank* PlayerTank = GetPlayerTank();
		if (PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s(AI) locked on player tank: %s"), *MyControlledTank->GetName(), *PlayerTank->GetName())
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s(AI) has not found player tank"),*MyControlledTank->GetName())
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not possessing a tank"))
	}

	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	APawn* Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!Pawn)return nullptr;
	return Cast<ATank>(Pawn);
}


