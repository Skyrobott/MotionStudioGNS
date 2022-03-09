// GEOBOT Corporight. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MSSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class MOTIONSTUDIO_API UMSSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	float UIVolume;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	float AmbientVolume;
};
