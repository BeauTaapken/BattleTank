// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"


// Just switch workaround off by commenting this
#define WORKAROUND
#include "ConstructorHelpers.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	
#ifdef WORKAROUND
	/*
	* W O R K A R O U N D   F O R   V A N I S H I N G   S T A T I C  M E S H
	* Set static mesh within the constructor manually
	*/
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_Track(TEXT("/Game/Tank/tank_fbx_Track"));
	UStaticMesh* TrackMesh = SM_Track.Object;
	static ConstructorHelpers::FObjectFinder<UPhysicalMaterial>PM_Track(TEXT("/Game/Tank/Track"));
	UPhysicalMaterial* TrackMat = PM_Track.Object;
	if (TrackMesh != nullptr && TrackMat != nullptr)
	{
		this->SetStaticMesh(TrackMesh);
		this->SetPhysMaterialOverride(TrackMat);
		this->SetNotifyRigidBodyCollision(true);
	}
#endif
}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (ASprungWheel* Wheel : Wheels) {
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const {
	TArray<ASprungWheel*> Result;
	
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for (USceneComponent* Child : Children) {
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) continue;

		AActor* SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SprungWheel = Cast<ASprungWheel>(SpawnedChild);
		if (!SprungWheel) continue;

		Result.Add(SprungWheel);
	}

	return Result;
}
