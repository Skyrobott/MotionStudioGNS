// GEOBOT Corporight. All rights reserved.


#include "Menu/Preview/MSPreviewPlayerController.h"

void AMSPreviewPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = false;
}
