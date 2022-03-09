// GEOBOT Corporight. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSInformationMenuWidget.generated.h"

class UButton;

UCLASS()
class MOTIONSTUDIO_API UMSInformationMenuWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		UButton* MenuButton;

private:
	UFUNCTION()
	void OnMenuButtonClicked();
};
