// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MSCoreTypes.h"
#include "MSMenuHUD.generated.h"

class UUserWidget;
UCLASS()
class MOTIONSTUDIO_API AMSMenuHUD : public AHUD
{
	GENERATED_BODY()
public:
    virtual void DrawHUD() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> MainMenuHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> ProjectsMenuHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> InformationMenuHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> SettingsMenuHUDWidgetClass;

    virtual void BeginPlay() override;

private:
    UPROPERTY()
        TMap<EMSMenuState, UUserWidget*> MenuWidgets;

    UPROPERTY()
        UUserWidget* CurrentWidget = nullptr;


    void OnMenuStateChanged(EMSMenuState State);
};
