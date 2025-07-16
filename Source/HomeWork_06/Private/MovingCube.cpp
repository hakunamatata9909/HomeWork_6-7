// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCube.h"

// Sets default values
AMovingCube::AMovingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = FMath::RandRange(100, 700);
	MaxRange = FMath::RandRange(0, 700);
	cubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("cubeMesh"));
	RootComponent = cubeMesh;
}

// Called when the game starts or when spawned
void AMovingCube::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector3d NewLocation = FVector3d(MoveSpeed*DeltaTime, 0.0f, 0.0f);

	AddActorLocalOffset(NewLocation);
	MovedDistance += NewLocation.X;

	if (FMath::Abs(MovedDistance) > MaxRange)
	{
		MoveSpeed = -MoveSpeed;
	}
}

