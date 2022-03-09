// GEOBOT Corporight. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSCoreTypes.h"
#include "MSSettingsWidget.generated.h"

class UButton;
class USlider;
class USoundMix;
class USoundClass;
class UMSSaveGame;
class UTextBlock;
UCLASS()
class MOTIONSTUDIO_API UMSSettingsWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* MainMenuButton;

	UPROPERTY(meta = (BindWidget))
		UButton* SaveMenuButton;

	UPROPERTY(meta = (BindWidget))
		USlider* UIVolume;

	UPROPERTY(meta = (BindWidget))
		USlider* AmbientVolume;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* UIValueText;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* AmbientValueText;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* SaveSucceedText;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* SaveSucceedAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundMix* SoundMixVolume;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundClass* SC_UI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundClass* SC_Ambient;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		FString SaveSlot = "Settings";




	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

private:

	UMSSaveGame* CurrentSaveGame;

	void LoadSaves();

	UFUNCTION()
		void MainMenuGame();

	UFUNCTION()
		void OnUIValueChanged(float Value);

	UFUNCTION()
		void OnAmbientValueChanged(float Value);

	UFUNCTION()
		void OnSaveMenuSettings();
};
