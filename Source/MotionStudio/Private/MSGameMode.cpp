// Fill out your copyright notice in the Description page of Project Settings.


#include "MSGameMode.h"
#include "Player/MSCharacter.h"
#include "Player/MSPlayerController.h"
AMSGameMode::AMSGameMode()
{
    DefaultPawnClass = AMSCharacter::StaticClass();
    PlayerControllerClass = AMSPlayerController::StaticClass();
}

void AMSGameMode::StartPlay()
{
    Super::StartPlay();
    SetMatchState(EMSMatchState::InProgress);
}

void AMSGameMode::SetMatchState(EMSMatchState State)
{
    if (MatchState == State) return;
    MatchState = State;
    OnMatchStateChanged.Broadcast(MatchState);
}

bool AMSGameMode::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
    const auto PauseSet = Super::SetPause(PC, CanUnpauseDelegate);
    if (PauseSet)
    {
        SetMatchState(EMSMatchState::Pause);
    }

    return PauseSet;
}

bool AMSGameMode::ClearPause()
{
    const auto PauseCleared = Super::ClearPause();
    if (PauseCleared)
    {
        SetMatchState(EMSMatchState::InProgress);
    }
    return PauseCleared;
}

void AMSGameMode::SetInformationState()
{
    SetMatchState(EMSMatchState::Information);
}

void AMSGameMode::SetInProgressState()
{
    SetMatchState(EMSMatchState::InProgress);

}