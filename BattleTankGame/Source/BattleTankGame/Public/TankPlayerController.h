// Copyright Lioncode Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
//Must be last include
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);
	
private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333;
	
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	void BeginPlay() override;

	void Tick(float DeltaTime) override;
	
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
