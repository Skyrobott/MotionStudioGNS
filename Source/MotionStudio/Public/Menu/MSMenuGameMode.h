// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MSCoreTypes.h"
#include "MSMenuGameMode.generated.h"

UCLASS()
class MOTIONSTUDIO_API AMSMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMSMenuGameMode();
	FOnMenuStateChangedSignature OnMenuStateChanged;
	void SetMainMenuState();
	void SetProjectsMenuState();
	void SetInformationMenuState();
	void SetSettingsMenuState();
protected:
	virtual void StartPlay() override;

private:
	EMSMenuState MenuState = EMSMenuState::WaitingToStart;

	void SetMenuState(EMSMenuState State);
};
