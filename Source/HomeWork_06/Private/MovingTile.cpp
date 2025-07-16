// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingTile.h"

// Sets default values
AMovingTile::AMovingTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	RootComponent = TileMesh;

}

// Called when the game starts or when spawned
void AMovingTile::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(StartLocation);
	
}

// Called every frame
void AMovingTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = FVector(0.0f, MoveSpeed * DeltaTime, 0.0f);
	AddActorLocalOffset(NewLocation);

	MovedDistance +=NewLocation.Y;
	if (MovedDistance > MaxRange || MovedDistance<=0)
	{
		MoveSpeed = -MoveSpeed;
	}
}

