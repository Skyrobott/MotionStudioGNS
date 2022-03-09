// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/UI/MSLevelsWidget.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/VerticalBox.h"
#include "MSGameInstance.h"
#include "MSCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Menu/UI/MSLevelItemWidget.h"
#include "Sound/SoundCue.h"
#include "Menu/MSMenuGameMode.h"

void UMSLevelsWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartButton && QuitButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UMSLevelsWidget::OnStartGame);
		QuitButton->OnClicked.AddDynamic(this, &UMSLevelsWidget::OnGoMenu);
	}

	InitLevelItems();
}

void UMSLevelsWidget::InitLevelItems()
{
	const auto MSGameInstance = GetMSGameInstance();
	if (!MSGameInstance) return;

	checkf(MSGameInstance->GetLevelsData().Num() != 0, TEXT("Levels data not be empty!"));
	int Count = 0;
	if (!LevelItemsBox1) return;
	LevelItemsBox1->ClearChildren();
	LevelItemsBox2->ClearChildren();
	for (auto LevelData : MSGameInstance->GetLevelsData())
	{
		Count++;
		const auto LevelItemWidget = CreateWidget<UMSLevelItemWidget>(GetWorld(), LevelItemWidgetClass);
		if (!LevelItemWidget) continue;

		LevelItemWidget->SetLevelData(LevelData);
		LevelItemWidget->OnLevelSelected.AddUObject(this, &UMSLevelsWidget::OnLevelSelected);
		if (Count <= 5)
			LevelItemsBox1->AddChild(LevelItemWidget);
		else
			LevelItemsBox2->AddChild(LevelItemWidget);

		LevelItemWidgets.Add(LevelItemWidget);
		
	}

	if (MSGameInstance->GetStartupLevel().LevelName.IsNone())
	{
		OnLevelSelected(MSGameInstance->GetLevelsData()[0]);
	}
	else
	{
		OnLevelSelected(MSGameInstance->GetStartupLevel());
	}
}

void UMSLevelsWidget::OnLevelSelected(const FLevelData& Data)
{
	const auto MSGameInstance = GetMSGameInstance();
	if (!MSGameInstance) return;

	MSGameInstance->SetStartupLevel(Data);

	for (auto LevelItemWidget : LevelItemWidgets)
	{
		if (LevelItemWidget)
		{
			const auto IsSelected = Data.LevelName == LevelItemWidget->GetLevelData().LevelName;
			LevelItemWidget->SetSelected(IsSelected);
		}
	}
}

UMSGameInstance* UMSLevelsWidget::GetMSGameInstance() const
{
	if (!GetWorld()) return nullptr;
	return GetWorld()->GetGameInstance<UMSGameInstance>();
}

void UMSLevelsWidget::OnStartGame()
{
	PlayAnimation(LoadAnimation);
	UGameplayStatics::PlaySound2D(GetWorld(), StartGameSound);
}


void UMSLevelsWidget::OnGoMenu()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->SetMainMenuState();
}

void UMSLevelsWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (Animation != LoadAnimation) return;
	
	const auto MSGameInstance = GetMSGameInstance();
	if (!MSGameInstance) return;

	UGameplayStatics::OpenLevel(this, MSGameInstance->GetStartupLevel().LevelName);
}