// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MSCoreTypes.h"
#include "MSCharacter.generated.h"


class UCameraComponent;
UCLASS()
class MOTIONSTUDIO_API AMSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMSCharacter(const FObjectInitializer& ObjInit);

protected:

	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UCameraComponent* CameraComponent;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	FOnKeyPressed OnKeyPressed;

private:
	bool WantsToRun = false;
	bool IsMovingForward = false;

	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void OnPressed();
};
