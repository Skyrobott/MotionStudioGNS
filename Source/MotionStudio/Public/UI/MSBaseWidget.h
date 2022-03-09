// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSBaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class MOTIONSTUDIO_API UMSBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void Show();
protected:
	UPROPERTY(meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* ShowAnimation;
};
