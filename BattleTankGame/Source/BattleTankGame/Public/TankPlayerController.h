// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
//Must be last include
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	ATankPlayerController();

	void BeginPlay() override;
	
	void Tick(float DeltaTime) override;

	/*Start the tank moving the barrel so that a shot would hti where the crosshair intersects the world*/
	void AimTowardsCrosshair();
	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
