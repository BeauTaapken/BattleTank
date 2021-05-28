// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"


// Just switch workaround off by commenting this
#define WORKAROUND
#include "ConstructorHelpers.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
	
#ifdef WORKAROUND
	/*
	* W O R K A R O U N D   F O R   V A N I S H I N G   S T A T I C  M E S H
	* Set static mesh within the constructor manually
	*/
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_Track(TEXT("/Game/Tank/tank_fbx_Track"));
	UStaticMesh* TrackMesh = SM_Track.Object;
	static ConstructorHelpers::FObjectFinder<UPhysicalMaterial>PM_Track(TEXT("/Game/Tank/Track"));
	UPhysicalMaterial* TrackMat = PM_Track.Object;
	if (ensure(TrackMesh == nullptr || TrackMat == nullptr)) { return; }
	this->SetStaticMesh(TrackMesh);
	this->SetPhysMaterialOverride(TrackMat);
#endif
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// Calculate the slipping speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	
	// Work-out the required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	
	// Calculate and apply sideways (F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2;

	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("OnHit event triggered"))
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
