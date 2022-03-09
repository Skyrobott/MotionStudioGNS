// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/MSMenuPlayerController.h"

void AMSMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}
