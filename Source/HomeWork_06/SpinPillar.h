// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinPillar.generated.h"

UCLASS()
class HOMEWORK_06_API ASpinPillar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinPillar();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EDITANYWHERE, BlueprintReadWrite, Category = "Pillar");
	UStaticMeshComponent* pillarMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pillar");
	float RotateSpeed = 0.0f;
	virtual void BeginPlay() override;
	FTimerHandle TimerHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RandomRotation()
	{
		// 회전 반전
		RotateSpeed = -RotateSpeed;

		// 다음 타이머 설정
		float RandomDelay = FMath::RandRange(1, 10);
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ASpinPillar::RandomRotation, RandomDelay, false);
	}
};
