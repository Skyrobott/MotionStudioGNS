// GEOBOT Corporight. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MSPreviewHUD.generated.h"

/**
 * 
 */
UCLASS()
class MOTIONSTUDIO_API AMSPreviewHUD : public AHUD
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> PreviewHUDWidgetClass;

	virtual void BeginPlay() override;
};
