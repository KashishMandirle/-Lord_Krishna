// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputAction.h"
#include "doudge.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
class UInputMappingContext;
class UInputAction;
class UInputMappingContext;
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class THEGOD_API Adoudge : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Adoudge();
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UCameraComponent* Camera;
	

	

public:	
	float Updown;
	



};
