// GEOBOT Corporight. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MSPreviewPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOTIONSTUDIO_API AMSPreviewPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
		virtual void BeginPlay() override;
};
