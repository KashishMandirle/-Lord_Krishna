// Fill out your copyright notice in the Description page of Project Settings.


#include "doudge.h"
#include "DrawDebugHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
Adoudge::Adoudge()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Staticmesh"));
	StaticMesh->SetupAttachment(Capsule);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	

}

// Called when the game starts or when spawned
void Adoudge::BeginPlay()
{
	

	
}

// Called every frame
void Adoudge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	//FString Actor = GetName();
	//FString Name = FString::Printf(TEXT("Delta:%f""Name:%s"), DeltaTime,*Actor);
	//GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green,Name);

	//UWorld* World = GetWorld();	
	//if (World)
	//{   float speed = 100.f;
	//	Updown += DeltaTime;
	//	float directionz =1.0f* FMath::Sin(Updown*5.f);
	//	AddActorWorldOffset(FVector(speed*DeltaTime,0.f, directionz));
	//	FVector location = GetActorLocation();
	//	DrawDebugSphere(World, location, 25.f, 30, FColor::Black,false,-1.0f);
	//}

}

// Called to bind functionality to input
void Adoudge::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

