// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.generated.h"

UCLASS()
class HOMEWORK_06_API AMovingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CubeMesh");
	UStaticMeshComponent* cubeMesh = nullptr;
	float MoveSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CubeSpeed")
	float MaxRange = 0.0f;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category= "CubeSpeed")
	float MovedDistance = 0.0f;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
