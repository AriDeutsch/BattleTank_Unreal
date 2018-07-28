// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite)float CrosshairsScreenRatioX;
	UPROPERTY(BlueprintReadWrite)float CrosshairsScreenRatioY;
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	ATank* GetControlledTank() const;
	void AimAtCrosshairs();
	bool GetCrosshairsHitLocation(FVector& OutHitLocation) const;
	UPROPERTY(EditAnywhere)float FireRange = 1000000; //10KM distance
};
