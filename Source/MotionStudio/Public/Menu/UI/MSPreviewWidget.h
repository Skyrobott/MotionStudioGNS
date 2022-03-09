// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSCoreTypes.h"
#include "MSPreviewWidget.generated.h"

UCLASS()
class MOTIONSTUDIO_API UMSPreviewWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeOnInitialized() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		float VideoRate;


	UPROPERTY(meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* LoadAnimation;

	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation);
private:
	FTimerHandle Handle;
	void OnTimerStopped();
};
