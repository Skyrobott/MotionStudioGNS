// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MSInformationWidget.h"
#include "Components/Button.h"
#include "MSGameMode.h"
bool UMSInformationWidget::Initialize()
{
	const auto InitStatus = Super::Initialize();

	if (ClearInformationButton)
	{
		ClearInformationButton->OnClicked.AddDynamic(this, &UMSInformationWidget::OnClearInformation);
	}
	return InitStatus;
}

void UMSInformationWidget::OnClearInformation()
{
	if (!GetWorld()) return;
	const auto GameMode = Cast<AMSGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode) return;
	GameMode->SetInProgressState();
}