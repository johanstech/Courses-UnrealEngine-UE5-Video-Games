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

	CurrentPosition = FVector(-13500, -2500, 4020);

	Velocity = 3;

	SetActorLocation(CurrentPosition);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalVector = FVector(1, 2, 3);

	CurrentPosition.X += Velocity;

	SetActorLocation(CurrentPosition);
}
