// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CapsuleComponenet"));
	RootComponent = BoxComponent;
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxComponent->SetCollisionObjectType(ECC_Pawn);
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Block);
	BoxComponent->SetSimulatePhysics(false);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponenet"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 350.0f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 80.0f));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArm);
	CameraComponent->bUsePawnControlRotation = false;
	CameraComponent->SetRelativeRotation(FRotator(-25.0f, 0.0f, 0.0f));

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponenet"));
	StaticMeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping,0);
		}
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentInput.IsNearlyZero())
	{
		FHitResult Hit;
		FVector Delta = CurrentInput * MoveSpeed * DeltaTime;
		RootComponent->MoveComponent(Delta, RootComponent->GetComponentRotation(), true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *Hit.GetActor()->GetName());
		}
	}

	if (!bIsGrounded)
	{
		Velocity.Z += Gravity * DeltaTime;
	}

	FVector Delta = (CurrentInput * MoveSpeed + FVector(0, 0, Velocity.Z)) * DeltaTime;

	FHitResult Hit;
	RootComponent->MoveComponent(Delta, RootComponent->GetComponentRotation(), true, &Hit);

	if (Hit.IsValidBlockingHit())
	{
		if (Hit.Normal.Z > 0.7f)
		{
			bIsGrounded = true;
			Velocity.Z = 0.0f;
		}
		else
		{
			bIsGrounded = false;
		}
	}
	else
	{
		bIsGrounded = false;
	}

	CurrentInput = FVector::ZeroVector;
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMyCharacter::Move);

	Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AMyCharacter::Look);

}

void AMyCharacter::Move(const FInputActionValue& value)
{
	FVector2D MoveInput = value.Get<FVector2D>();
	FRotator ControlRotation = Controller->GetControlRotation();
	FRotator YawRotation(0, ControlRotation.Yaw, 0);

	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(ForwardDirection, MoveInput.X);
	AddMovementInput(RightDirection, MoveInput.Y);

	CurrentInput = (ForwardDirection * MoveInput.X + RightDirection * MoveInput.Y).GetClampedToMaxSize(1.0f);
}

void AMyCharacter::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();

	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);

}

