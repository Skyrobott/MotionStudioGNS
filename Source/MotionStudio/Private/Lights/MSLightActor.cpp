// Fill out your copyright notice in the Description page of Project Settings.


#include "Lights/MSLightActor.h"

AMSLightActor::AMSLightActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;
}


void AMSLightActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMSLightActor::SetActorHiddenInGame(bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);
}
