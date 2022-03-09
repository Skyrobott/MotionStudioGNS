// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/UI/MSMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Sound/SoundCue.h"
#include "MSCoreTypes.h"
#include "Menu/MSMenuGameMode.h"

void UMSMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartButton && InformationMenuButton && QuitButton && SettingsButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UMSMenuWidget::OnStartGame);
		InformationMenuButton->OnClicked.AddDynamic(this, &UMSMenuWidget::OnInformationMenu);
		SettingsButton->OnClicked.AddDynamic(this, &UMSMenuWidget::OnSettingsGame);
		QuitButton->OnClicked.AddDynamic(this, &UMSMenuWidget::OnQuitGame);
	}
	
}

void UMSMenuWidget::NativeConstruct()
{
	PlayAnimation(StartAnimation);
}

void UMSMenuWidget::OnStartGame()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->SetProjectsMenuState();
}

void UMSMenuWidget::OnInformationMenu()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->SetInformationMenuState();
}

void UMSMenuWidget::OnSettingsGame()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->SetSettingsMenuState();
}

void UMSMenuWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

