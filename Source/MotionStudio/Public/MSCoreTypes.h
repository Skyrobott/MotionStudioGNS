#pragma once
#include "MSCoreTypes.generated.h"
//iput action
DECLARE_MULTICAST_DELEGATE(FOnKeyPressed);

//game states
UENUM(BlueprintType)
enum class EMSMatchState : uint8
{
    WaitingToStart = 0,
    InProgress,
    Pause,
    Overlap,
    Information
};

//game states
UENUM(BlueprintType)
enum class EMSMenuState : uint8
{
    WaitingToStart = 0,
    MainMenu,
    ProjectsMenu,
    InformationMenu,
    SettingsMenu
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChangedSignature, EMSMatchState);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnMenuStateChangedSignature, EMSMenuState);

USTRUCT(BlueprintType)
struct FLevelData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Level")
        FName LevelName = NAME_None;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Level")
        FName LevelDisplayName = NAME_None;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Level")
        UTexture2D* LevelThumb;
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnLevelSelectedSignature, const FLevelData&);