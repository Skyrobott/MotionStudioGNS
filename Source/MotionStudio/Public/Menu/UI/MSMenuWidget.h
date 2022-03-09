// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSCoreTypes.h"
#include "MSMenuWidget.generated.h"


class UButton;
class USoundCue;

UCLASS()
class MOTIONSTUDIO_API UMSMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* StartButton;

	UPROPERTY(meta = (BindWidget))
		UButton* InformationMenuButton;

	UPROPERTY(meta = (BindWidget))
		UButton* SettingsButton;

	UPROPERTY(meta = (BindWidget))
		UButton* QuitButton;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* StartAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundCue* StartGameSound;

	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	//virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation);

private:

	UFUNCTION()
		void OnStartGame();

	UFUNCTION()
		void OnInformationMenu();

	UFUNCTION()
		void OnSettingsGame();

	UFUNCTION()
		void OnQuitGame();

	
};
