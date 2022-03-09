// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MSCoreTypes.h"
#include "MSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOTIONSTUDIO_API AMSPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	void OnPauseGame();
	void OnInformationStatePressed();
	void OnMatchStateChanged(EMSMatchState State);
};
