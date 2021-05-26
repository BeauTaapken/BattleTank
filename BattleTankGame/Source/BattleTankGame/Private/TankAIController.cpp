// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	if(ensure(PlayerTank))
	{
		auto ControlledTank = Cast<ATank>(GetPawn());

		MoveToActor(PlayerTank, AcceptanceRadius);
		
	    ControlledTank->AimAt(PlayerTank->GetActorLocation());
	    ControlledTank->Fire();
	}	
}
