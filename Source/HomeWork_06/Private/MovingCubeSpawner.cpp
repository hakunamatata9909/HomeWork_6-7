// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCubeSpawner.h"
#include "MovingCube.h"

// Sets default values
AMovingCubeSpawner::AMovingCubeSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingCubeSpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 4; i++)
	{
		FVector SpawnLocation = FVector(0.0f, FMath::RandRange(400.0, -1200.0), 50.0f);
		GetWorld()->SpawnActor<AMovingCube>(MovingCubeClass,SpawnLocation,FRotator::ZeroRotator);
	}
}

// Called every frame
void AMovingCubeSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

