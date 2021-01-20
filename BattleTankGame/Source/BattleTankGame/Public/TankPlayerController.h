// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
//Must be last include
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333;
	
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	void BeginPlay() override;

	void Tick(float DeltaTime) override;
	
	ATank* GetControlledTank() const;
	
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
