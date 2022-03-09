// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/UI/MSLevelItemWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UMSLevelItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (LevelSelectButton)
	{
		LevelSelectButton->OnClicked.AddDynamic(this, &UMSLevelItemWidget::OnLevelItemClicked);
		LevelSelectButton->OnHovered.AddDynamic(this, &UMSLevelItemWidget::OnLevelItemSelected);
		LevelSelectButton->OnUnhovered.AddDynamic(this, &UMSLevelItemWidget::OnLevelItemUnSelected);
	}
}

void UMSLevelItemWidget::SetLevelData(const FLevelData& Data)
{
	LevelData = Data;

	if (LevelNameTextBlock)
	{
		LevelNameTextBlock->SetText(FText::FromName(Data.LevelDisplayName));
	}

	if (LevelImage)
	{
		LevelImage->SetBrushFromTexture(Data.LevelThumb);
	}
}


void UMSLevelItemWidget::SetSelected(bool IsSelected)
{
	if (FrameImage)
	{
		FrameImage->SetVisibility(IsSelected ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
		OpacityImage->SetVisibility(IsSelected ? ESlateVisibility::Hidden : ESlateVisibility::SelfHitTestInvisible);
		IsItemSelected = IsSelected;
	}
}

void UMSLevelItemWidget::OnLevelItemClicked()
{
	OnLevelSelected.Broadcast(LevelData);
}

void UMSLevelItemWidget::OnLevelItemSelected()
{
	if (!IsItemSelected)
	{
		OpacityImage->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UMSLevelItemWidget::OnLevelItemUnSelected()
{
	if (!IsItemSelected)
	{
		OpacityImage->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
}