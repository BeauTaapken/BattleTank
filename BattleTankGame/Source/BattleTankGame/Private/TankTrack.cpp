// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"


// Just switch workaround off by commenting this
#define WORKAROUND
#include "ConstructorHelpers.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

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

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

void UTankTrack::ApplySidewaysForce()
{
	// Work-out the required acceleration this frame to correct
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideways (F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2;

	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
