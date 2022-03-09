// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MSCoreTypes.h"
#include "MSGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MOTIONSTUDIO_API UMSGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	FLevelData GetStartupLevel() const { return StartupLevel; }
	void SetStartupLevel(const FLevelData& Data) { StartupLevel = Data; }
	TArray<FLevelData> GetLevelsData() const { return LevelsData; }
	FName GetMenuLevelName() const { return MenuLevelName; }
	FName GetPreviewLevelName() const { return PreviewLevelName; }
protected:

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		TArray<FLevelData> LevelsData;

		

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FName MenuLevelName = NAME_None;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FName PreviewLevelName = NAME_None;

private:
	FLevelData StartupLevel;
};
