// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MSBaseWidget.h"
#include "MSProgressWidget.generated.h"

/**
 * 
 */
UCLASS()
class MOTIONSTUDIO_API UMSProgressWidget : public UMSBaseWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	bool IsPlayerOverlapping() const;
};
