// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingTile.generated.h"

UCLASS()
class HOMEWORK_06_API AMovingTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EDITANYWHERE, BlueprintReadWrite, Category = "Tile");
	UStaticMeshComponent* TileMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Transform")
	float MoveSpeed = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile|Transform")
	float MaxRange = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Tile|Transform")
	FVector3d StartLocation = FVector3d::ZeroVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tile|Transform")
	float MovedDistance = 0.0f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
