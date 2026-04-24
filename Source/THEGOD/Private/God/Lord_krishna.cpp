// Fill out your copyright notice in the Description page of Project Settings.


#include "God/Lord_krishna.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
ALord_krishna::ALord_krishna()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh(), TEXT("spine2"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ALord_krishna::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(LordMappingComtext, 0);
	 }
	}
}

// Called every frame
void ALord_krishna::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALord_krishna::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector=Value.Get<FVector2D>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YaWRotation (0.f, Rotation.Yaw, 0.f);

	const FVector ForwardVector = FRotationMatrix(YaWRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardVector, MovementVector.Y);
	const FVector Right = FRotationMatrix(YaWRotation).GetUnitAxis(EAxis::Y);	
	AddMovementInput(Right, MovementVector.X);

	

}




// Called to bind functionality to input
void ALord_krishna::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	{
		Input->BindAction(Inputs, ETriggerEvent::Triggered, this, &ALord_krishna::Move);
	}





}

