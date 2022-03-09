// GEOBOT Corporight. All rights reserved.


#include "Menu/Preview/MSPreviewGameMode.h"
#include "Menu/Preview/MSPreviewPlayerController.h"
#include "Menu/Preview/MSPreviewHUD.h"

AMSPreviewGameMode::AMSPreviewGameMode()
{
	PlayerControllerClass = AMSPreviewPlayerController::StaticClass();
	HUDClass = AMSPreviewHUD::StaticClass();
}