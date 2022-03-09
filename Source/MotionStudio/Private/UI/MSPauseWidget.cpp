// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MSPauseWidget.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MSGameInstance.h"
bool UMSPauseWidget::Initialize()
{
	const auto InitStatus =  Super::Initialize();

	if (ClearPauseButton && MainMenuButton)
	{
		ClearPauseButton->OnClicked.AddDynamic(this, &UMSPauseWidget::OnClearPause);
		MainMenuButton->OnClicked.AddDynamic(this, &UMSPauseWidget::OnGoToMainMenu);
	}
	return InitStatus;
}

void UMSPauseWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (!GetWorld()) return;

	const auto MSGameInstance = GetWorld()->GetGameInstance<UMSGameInstance>();
	if (!MSGameInstance) return;

	UGameplayStatics::OpenLevel(this, MSGameInstance->GetMenuLevelName());
}

void UMSPauseWidget::OnClearPause()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	GetWorld()->GetAuthGameMode()->ClearPause();
}

void UMSPauseWidget::OnGoToMainMenu()
{
	PlayAnimation(LoadAnimation);
}