// Copyright Lioncode Ltd.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


// Forward declerations
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();
	
private:
	// Sets default values for this pawn's properties
	ATank();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;
	
	//TODO remove this reference
	//Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
