// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSPauseWidget.generated.h"

class UButton;
UCLASS()
class MOTIONSTUDIO_API UMSPauseWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* ClearPauseButton;

	UPROPERTY(meta = (BindWidget))
		UButton* MainMenuButton;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* LoadAnimation;

	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation);    
private:
	UFUNCTION()
		void OnClearPause();

	UFUNCTION()
		void OnGoToMainMenu();
};
