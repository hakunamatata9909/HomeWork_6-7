// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "InputActionValue.h"
#include "MyCharacter.generated.h"


class UInputAction;
class UInputMappingContext;

UCLASS()
class HOMEWORK_06_API AMyCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " StaticMesh");
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly,Category="InputAction")
	UInputMappingContext* InputMapping;
	UPROPERTY(EditDefaultsOnly, Category = "InputAction")
	UInputAction* IA_Move;
	UPROPERTY(EditDefaultsOnly, Category = "InputAction")
	UInputAction* IA_Look;

	UFloatingPawnMovement* FloatingMovement;
	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
