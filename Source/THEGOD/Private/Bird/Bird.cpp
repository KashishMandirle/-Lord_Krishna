// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Capsule);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(BirdMapping, 0);
		}
	}
}

void ABird::RUN(const FInputActionValue& Value)
{
	const FVector2D Running = Value.Get<FVector2D>();
		if (Controller )
		{
			float speed = 500.f;
			FVector Forward = GetActorForwardVector();
			FVector Right = GetActorRightVector();
			FVector Direction = (Forward * Running.Y) + (Right * Running.X);
			AddActorLocalOffset(Direction * speed * GetWorld()->GetDeltaSeconds(),true);

		}
}

void ABird::LOOKXY(const FInputActionValue& Value)
{
	const FVector2D Looking = Value.Get<FVector2D>();
	if (Controller)
	{
		AddControllerYawInput(Looking.X);
		AddControllerPitchInput(Looking.Y);
	}
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInput)
	{
		EnhancedInput->BindAction(IA_WS,ETriggerEvent::Triggered,this, &ABird::RUN);
		EnhancedInput->BindAction(Look, ETriggerEvent::Triggered, this, &ABird::LOOKXY);
	}
		
}

