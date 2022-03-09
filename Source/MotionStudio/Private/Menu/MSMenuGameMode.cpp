// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/MSMenuGameMode.h"
#include "Menu/MSMenuPlayerController.h"
#include "Menu/UI/MSMenuHUD.h"

AMSMenuGameMode::AMSMenuGameMode()
{
	PlayerControllerClass = AMSMenuPlayerController::StaticClass();
	HUDClass = AMSMenuHUD::StaticClass();
}

void AMSMenuGameMode::StartPlay()
{
	Super::StartPlay();
	SetMenuState(EMSMenuState::MainMenu);
}

void AMSMenuGameMode::SetMenuState(EMSMenuState State)
{
	if (MenuState == State) return;
	MenuState = State;
	OnMenuStateChanged.Broadcast(MenuState);
}

void AMSMenuGameMode::SetProjectsMenuState()
{
	SetMenuState(EMSMenuState::ProjectsMenu);
}

void AMSMenuGameMode::SetMainMenuState()
{
	SetMenuState(EMSMenuState::MainMenu);
}

void AMSMenuGameMode::SetInformationMenuState()
{
	SetMenuState(EMSMenuState::InformationMenu);
}

void AMSMenuGameMode::SetSettingsMenuState()
{
	SetMenuState(EMSMenuState::SettingsMenu);
}