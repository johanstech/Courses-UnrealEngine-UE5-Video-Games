// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// FVector(-13500, -2500, 4020);
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move platform forwards
	// Get current location
	FVector CurrentLocation = GetActorLocation();

	// Update vector
	CurrentLocation += PlatformVelocity * DeltaTime;

	// Set the location
	SetActorLocation(CurrentLocation);

	// Send platform back if gone too far
	// Check how far we've moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	// Reverse direction if gone too far
	if (DistanceMoved >= MoveDistance)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}
