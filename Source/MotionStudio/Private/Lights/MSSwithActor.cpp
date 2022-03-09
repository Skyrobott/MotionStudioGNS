// Fill out your copyright notice in the Description page of Project Settings.


#include "Lights/MSSwithActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Lights/MSLightActor.h"
#include "Components/InputComponent.h"
#include "Player/MSCharacter.h"
#include "MSGameMode.h"
#include "Sound/SoundCue.h"
DEFINE_LOG_CATEGORY_STATIC(LogMSSwitchActor, All, All);

AMSSwithActor::AMSSwithActor()
{

	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	RootComponent = BoxComponent;

	Switch = CreateDefaultSubobject<UStaticMeshComponent>("Switch");
	Switch->SetupAttachment(RootComponent);
	Switch->SetRelativeLocation(FVector(-10.0f, 0.0f, 0.0f));

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMSSwithActor::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AMSSwithActor::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AMSSwithActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMSSwithActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (GetWorld())
		{
			const auto GameMode = Cast<AMSGameMode>(GetWorld()->GetAuthGameMode());
			if (GameMode)
			{
				GameMode->SetPlayerOverlapping(true);
			}
		}

		const auto Player = Cast<AMSCharacter>(OtherActor);
		Player->OnKeyPressed.AddUObject(this, &AMSSwithActor::OnSwitchClicked);
		
	}
}

void AMSSwithActor::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (GetWorld())
		{
			const auto GameMode = Cast<AMSGameMode>(GetWorld()->GetAuthGameMode());
			if (GameMode)
			{
				GameMode->SetPlayerOverlapping(false);
			}
		}

		const auto Player = Cast<AMSCharacter>(OtherActor);
		Player->OnKeyPressed.Clear();
	}
}

void AMSSwithActor::OnSwitchClicked()
{
	TArray<AActor*> LightActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMSLightActor::StaticClass(), LightActors);
	for (auto LightActor : LightActors)
	{
		const auto LightOne = Cast<AMSLightActor>(LightActor);
		if (LightOne->GetLightID() == LightID)
		{
			LightOne->SetActorHiddenInGame(HiddenInGame);
		}
	}
	HiddenInGame = HiddenInGame ? false : true;
	UGameplayStatics::PlaySound2D(GetWorld(), ClickSwitchSound);
}
