// GEOBOT Corporight. All rights reserved.


#include "Menu/Preview/MSPreviewHUD.h"
#include "Blueprint/UserWidget.h"
void AMSPreviewHUD::BeginPlay()
{
	Super::BeginPlay();
	
	const auto PreviewWidget = CreateWidget<UUserWidget>(GetWorld(), PreviewHUDWidgetClass);
	if (!PreviewWidget) return;
	PreviewWidget->AddToViewport();
}