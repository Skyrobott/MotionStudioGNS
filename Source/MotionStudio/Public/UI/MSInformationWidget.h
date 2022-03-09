// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSInformationWidget.generated.h"

class UButton;
UCLASS()
class MOTIONSTUDIO_API UMSInformationWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* ClearInformationButton;

private:
	UFUNCTION()
		void OnClearInformation();
};
