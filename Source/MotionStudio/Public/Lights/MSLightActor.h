// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MSLightActor.generated.h"

class ULightComponent;

UCLASS()
class MOTIONSTUDIO_API AMSLightActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMSLightActor();
	int32 GetLightID() { return LightID; }

	virtual void SetActorHiddenInGame(bool bNewHidden);
protected:

	virtual void BeginPlay() override;
	

	UPROPERTY(EditAnywhere, Category = "Light")
		int32 LightID;


};
