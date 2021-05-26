// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"


// Just switch workaround off by commenting this
#define WORKAROUND
#include "ConstructorHelpers.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

/*
 * W O R K A R O U N D   F O R   V A N I S H I N G   S T A T I C  M E S H
 * Set static mesh within the constructor manually
 */
UTankTrack::UTankTrack()
{
#ifdef WORKAROUND
	// We simply use the Engine Cone Basic Shape
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_Track(TEXT("/Game/Tank/tank_fbx_Track"));
	UStaticMesh* TrackMesh = SM_Track.Object;
	static ConstructorHelpers::FObjectFinder<UPhysicalMaterial>PM_Track(TEXT("/Game/Tank/Track"));
	UPhysicalMaterial* TrackMat = PM_Track.Object;
	if (ensure(TrackMesh == nullptr || TrackMat == nullptr)) { return; }
	this->SetStaticMesh(TrackMesh);
	this->SetPhysMaterialOverride(TrackMat);
#endif
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
