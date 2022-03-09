// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MSPlayerController.h"
#include "Gameframework/GameModeBase.h"
#include "MSGameMode.h"

void AMSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		const auto GameMode = Cast<AMSGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &AMSPlayerController::OnMatchStateChanged);
		}
	}
}

void AMSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (!InputComponent) return;
	InputComponent->BindAction("Pause", IE_Pressed, this, &AMSPlayerController::OnPauseGame);
	InputComponent->BindAction("Information", IE_Pressed, this, &AMSPlayerController::OnInformationStatePressed);
}

void AMSPlayerController::OnPauseGame()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	GetWorld()->GetAuthGameMode()->SetPause(this);
}

void AMSPlayerController::OnInformationStatePressed()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	const auto GameMode = Cast<AMSGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->SetInformationState();
}


void AMSPlayerController::OnMatchStateChanged(EMSMatchState State)
{
	if (State == EMSMatchState::InProgress)
	{
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
	else
	{
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}