// GEOBOT Corporight. All rights reserved.


#include "Menu/UI/MSInformationMenuWidget.h"
#include "Components/Button.h"
#include "Menu/MSMenuGameMode.h"

void UMSInformationMenuWidget::NativeOnInitialized()
{
	if (MenuButton)
	{
		MenuButton->OnClicked.AddDynamic(this, &UMSInformationMenuWidget::OnMenuButtonClicked);
	}
}

void UMSInformationMenuWidget::OnMenuButtonClicked()
{
	if (!GetWorld() && !GetWorld()->GetAuthGameMode()) return;
	const auto GameMode = Cast<AMSMenuGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->SetMainMenuState();
}