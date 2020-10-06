// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward decleration
class UTankTurret;
class UTankBarrel;


//Holds barrel properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetTurretReference(UTankTurret* TurretToSet);
	
	void SetBarrelReference(UTankBarrel* BarrelToSet);

private:
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};
