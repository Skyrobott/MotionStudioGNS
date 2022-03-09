// Fill out your copyright notice in the Description page of Project Settings.
#include "UI/MSPlayerHUD.h"
#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"
#include "MSGameMode.h"
DEFINE_LOG_CATEGORY_STATIC(LogMSPlayerHUD, All, All);
void AMSPlayerHUD::DrawHUD()
{

    Super::DrawHUD();
    // DrawCrossHair();
}

void AMSPlayerHUD::BeginPlay()
{

    Super::BeginPlay();

    GameWidgets.Add(EMSMatchState::InProgress, CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass));
    GameWidgets.Add(EMSMatchState::Pause, CreateWidget<UUserWidget>(GetWorld(), PauseHUDWidgetClass));
    GameWidgets.Add(EMSMatchState::Overlap, CreateWidget<UUserWidget>(GetWorld(), OverlapHUDWidgetClass));
    GameWidgets.Add(EMSMatchState::Information, CreateWidget<UUserWidget>(GetWorld(), InformationHUDWidgetClass));

    for (auto GameWidgetPair : GameWidgets)
    {
        const auto GameWidget = GameWidgetPair.Value;
        if (!GameWidget) continue;
        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GetWorld())
    {
        const auto GameMode = Cast<AMSGameMode>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &AMSPlayerHUD::OnMatchStateChanged);
        }
    }
}

void AMSPlayerHUD::OnMatchStateChanged(EMSMatchState State)
{
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GameWidgets.Contains(State))
    {
        CurrentWidget = GameWidgets[State];
    }

    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
    }
    UE_LOG(LogMSPlayerHUD, Display, TEXT("Match state change: %s"), *UEnum::GetValueAsString(State));
}
