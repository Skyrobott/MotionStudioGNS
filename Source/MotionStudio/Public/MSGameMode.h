// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MSCoreTypes.h"
#include "MSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MOTIONSTUDIO_API AMSGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
		AMSGameMode();
		FOnMatchStateChangedSignature OnMatchStateChanged;
		virtual void StartPlay() override;

		void SetInformationState();
		void SetInProgressState();
		void SetPlayerOverlapping(bool value) { IsPlayerOverlapping = value; }
		bool GetPlayerOverlapping() { return IsPlayerOverlapping; }
		virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
		virtual bool ClearPause() override;
private:
	EMSMatchState MatchState = EMSMatchState::WaitingToStart;
	


	void SetMatchState(EMSMatchState State);
	bool IsPlayerOverlapping = false;
};
