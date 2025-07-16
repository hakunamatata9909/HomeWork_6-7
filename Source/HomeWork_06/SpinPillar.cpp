// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinPillar.h"

// Sets default values
ASpinPillar::ASpinPillar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	pillarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillarMesh"));
	RootComponent = pillarMesh;

}

// Called when the game starts or when spawned
void ASpinPillar::BeginPlay()
{
	Super::BeginPlay();
	RandomRotation();
}

// Called every frame
void ASpinPillar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.0f, 0.0f, RotateSpeed * DeltaTime));
}

