// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MSCoreTypes.h"
#include "MSPlayerHUD.generated.h"

UCLASS()
class MOTIONSTUDIO_API AMSPlayerHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> PauseHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> OverlapHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> InformationHUDWidgetClass;

    virtual void BeginPlay() override;

private:
    UPROPERTY()
        TMap<EMSMatchState, UUserWidget*> GameWidgets;

    UPROPERTY()
        UUserWidget* CurrentWidget = nullptr;


    void OnMatchStateChanged(EMSMatchState State);
};
