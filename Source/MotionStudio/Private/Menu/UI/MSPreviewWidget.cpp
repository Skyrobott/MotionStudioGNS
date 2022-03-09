// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/UI/MSPreviewWidget.h"
#include "MSCoreTypes.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MSGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogMSPreviewWidget, All, All);

void UMSPreviewWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	GetWorld()->GetTimerManager().SetTimer(Handle, this, &UMSPreviewWidget::OnTimerStopped, VideoRate, false);
}

void UMSPreviewWidget::OnTimerStopped()
{
	GetWorld()->GetTimerManager().ClearTimer(Handle);
	PlayAnimation(LoadAnimation);
}

void UMSPreviewWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (!GetWorld()) return;

	const auto MSGameInstance = GetWorld()->GetGameInstance<UMSGameInstance>();
	if (!MSGameInstance) return;

	UGameplayStatics::OpenLevel(this, MSGameInstance->GetMenuLevelName());
	UE_LOG(LogMSPreviewWidget, Display, TEXT("Level has done!"));
}