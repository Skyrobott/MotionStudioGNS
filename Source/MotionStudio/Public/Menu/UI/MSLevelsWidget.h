// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSCoreTypes.h"
#include "MSLevelsWidget.generated.h"

class UButton;
class UHorizontalBox;
class UVerticalBox;
class UMSGameInstance;
class UMSLevelItemWidget;
class USoundCue;

UCLASS()
class MOTIONSTUDIO_API UMSLevelsWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;
	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation);

	UPROPERTY(meta = (BindWidget))
		UButton* StartButton;

	UPROPERTY(meta = (BindWidget))
		UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
		UHorizontalBox* LevelItemsBox1;

	UPROPERTY(meta = (BindWidget))
		UHorizontalBox* LevelItemsBox2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> LevelItemWidgetClass;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* LoadAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundCue* StartGameSound;

private:
	TArray<UMSLevelItemWidget*> LevelItemWidgets;

	void InitLevelItems();
	void OnLevelSelected(const FLevelData& Data);
	UMSGameInstance* GetMSGameInstance() const;

	UFUNCTION()
		void OnStartGame();

	UFUNCTION()
		void OnGoMenu();
};
