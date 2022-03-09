// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/UI/MSMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Menu/MSMenuGameMode.h"
DEFINE_LOG_CATEGORY_STATIC(LogMSMenuHUD, All, All);
void AMSMenuHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AMSMenuHUD::BeginPlay()
{
	Super::BeginPlay();

    MenuWidgets.Add(EMSMenuState::MainMenu, CreateWidget<UUserWidget>(GetWorld(), MainMenuHUDWidgetClass));
    MenuWidgets.Add(EMSMenuState::ProjectsMenu, CreateWidget<UUserWidget>(GetWorld(), ProjectsMenuHUDWidgetClass));
    MenuWidgets.Add(EMSMenuState::InformationMenu, CreateWidget<UUserWidget>(GetWorld(), InformationMenuHUDWidgetClass));
    MenuWidgets.Add(EMSMenuState::SettingsMenu, CreateWidget<UUserWidget>(GetWorld(), SettingsMenuHUDWidgetClass));

    for (auto MenuWidgetPair : MenuWidgets)
    {
        const auto MenuWidget = MenuWidgetPair.Value;
        if (!MenuWidget) continue;
        MenuWidget->AddToViewport();
        UE_LOG(LogMSMenuHUD, Display, TEXT("Adding"));
        MenuWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GetWorld())
    {
        const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMenuStateChanged.AddUObject(this, &AMSMenuHUD::OnMenuStateChanged);
        }
    }
}

void AMSMenuHUD::OnMenuStateChanged(EMSMenuState State)
{
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (MenuWidgets.Contains(State))
    {
        CurrentWidget = MenuWidgets[State];
    }

    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
    }
    UE_LOG(LogMSMenuHUD, Display, TEXT("Match state change: %s"), *UEnum::GetValueAsString(State));
}
