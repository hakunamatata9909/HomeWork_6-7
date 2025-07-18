// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCubeSpawner.generated.h"

class AMovingCube;
UCLASS()
class HOMEWORK_06_API AMovingCubeSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingCubeSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SelectCube");
	TSubclassOf<AMovingCube> MovingCubeClass; 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
