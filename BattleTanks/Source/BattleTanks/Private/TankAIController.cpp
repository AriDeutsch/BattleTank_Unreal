// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* MyControlledTank = GetControlledTank();
	if (MyControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possessing %s"), *MyControlledTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not possessing a tank"))
	}

	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAtTarget(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	APawn* Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(Pawn);
}


