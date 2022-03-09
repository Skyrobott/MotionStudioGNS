// GEOBOT Corporight. All rights reserved.


#include "Menu/UI/MSSettingsWidget.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "Sound/SoundMix.h"
#include "Sound/SoundClass.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Saves/MSSaveGame.h"
#include "Menu/MSMenuGameMode.h"

DEFINE_LOG_CATEGORY_STATIC(LogSettings, All, All);

void UMSSettingsWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	if (MainMenuButton && UIVolume && AmbientVolume && SaveMenuButton)
	{
		MainMenuButton->OnClicked.AddDynamic(this, &UMSSettingsWidget::MainMenuGame);
		SaveMenuButton->OnClicked.AddDynamic(this, &UMSSettingsWidget::OnSaveMenuSettings);
		UIVolume->OnValueChanged.AddDynamic(this, &UMSSettingsWidget::OnUIValueChanged);
		AmbientVolume->OnValueChanged.AddDynamic(this, &UMSSettingsWidget::OnAmbientValueChanged);
	}
	UGameplayStatics::SetBaseSoundMix(GetWorld(), SoundMixVolume);
	LoadSaves();
}

void UMSSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	LoadSaves();
}

void UMSSettingsWidget::MainMenuGame()
{
	StopAnimation(SaveSucceedAnimation);
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->SetMainMenuState();
}

void UMSSettingsWidget::OnUIValueChanged(float Value)
{
	const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());

	UGameplayStatics::SetSoundMixClassOverride(GetWorld(), SoundMixVolume, SC_UI, Value, 1.0f, 0.0f, true);

	UIValueText->SetText(FText::FromString(FString::FromInt(Value * 100.0f)));
}

void UMSSettingsWidget::OnAmbientValueChanged(float Value)
{
	const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());

	UGameplayStatics::SetSoundMixClassOverride(GetWorld(), SoundMixVolume, SC_Ambient, Value, 1.0f, 0.0f, true);

	AmbientValueText->SetText(FText::FromString(FString::FromInt(Value * 100.0f)));
}

void UMSSettingsWidget::OnSaveMenuSettings()
{
	if (!CurrentSaveGame && !SaveSucceedAnimation) return;
	CurrentSaveGame->UIVolume = UIVolume->GetValue();
	CurrentSaveGame->AmbientVolume = AmbientVolume->GetValue();
	UGameplayStatics::SaveGameToSlot(CurrentSaveGame, SaveSlot, 0);
	PlayAnimation(SaveSucceedAnimation);
}

void UMSSettingsWidget::LoadSaves()
{
	if (UGameplayStatics::DoesSaveGameExist(SaveSlot, 0))
	{
		CurrentSaveGame = Cast<UMSSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot, 0));
		if (CurrentSaveGame == nullptr)
		{
			return;
		}
		float VolumeUI = CurrentSaveGame->UIVolume;
		float VolumeAmbient = CurrentSaveGame->AmbientVolume;
		UIVolume->SetValue(VolumeUI);
		AmbientVolume->SetValue(VolumeAmbient);
		UGameplayStatics::SetSoundMixClassOverride(GetWorld(), SoundMixVolume, SC_UI, VolumeUI, 1.0f, 0.0f, true);
		UGameplayStatics::SetSoundMixClassOverride(GetWorld(), SoundMixVolume, SC_Ambient, VolumeAmbient, 1.0f, 0.0f, true);
		UIValueText->SetText(FText::FromString(FString::FromInt(CurrentSaveGame->UIVolume * 100.0f)));
		AmbientValueText->SetText(FText::FromString(FString::FromInt(CurrentSaveGame->AmbientVolume * 100.0f)));
	}
	else
	{
		UIVolume->SetValue(1.0f);
		AmbientVolume->SetValue(1.0f);

		UIValueText->SetText(FText::FromString(FString::FromInt(1.0f * 100.0f)));
		AmbientValueText->SetText(FText::FromString(FString::FromInt(1.0f * 100.0f)));

		UGameplayStatics::SetSoundMixClassOverride(GetWorld(), SoundMixVolume, SC_UI, 1.0f, 1.0f, 0.0f, true);
		UGameplayStatics::SetSoundMixClassOverride(GetWorld(), SoundMixVolume, SC_Ambient, 1.0f, 1.0f, 0.0f, true);

		CurrentSaveGame = Cast<UMSSaveGame>(UGameplayStatics::CreateSaveGameObject(UMSSaveGame::StaticClass()));
	}
}

