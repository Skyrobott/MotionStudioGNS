// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MSProgressWidget.h"
#include "Lights/MSSwithActor.h"
#include "MSGameMode.h"
bool UMSProgressWidget::IsPlayerOverlapping() const
{
	bool value = false;
	if (GetWorld())
	{
		const auto GameMode = Cast<AMSGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
		value =  GameMode->GetPlayerOverlapping();
		}
	}
	return value;
}