// Fill out your copyright notice in the Description page of Project Settings.


#include "Doors/MSOpenDoor.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "MSGameMode.h"
#include "MSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
AMSOpenDoor::AMSOpenDoor()
{

	PrimaryActorTick.bCanEverTick = true;


	Open = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->InitBoxExtent(FVector(100.0f, 50.0f, 50.0f));
	RootComponent = BoxComponent;

	Door = CreateDefaultSubobject<UStaticMeshComponent>("Door");
	Door->SetRelativeLocation(FVector(0.0f, 50.0f, -50.0f));
	Door->SetupAttachment(RootComponent);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMSOpenDoor::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AMSOpenDoor::OnOverlapEnd);
}


void AMSOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMSOpenDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorRotation = Door->GetRelativeRotation();

	if (Open)
	{
		Door->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.0f, RotateValue, 0.0f)), 0.05));
	}
	else
	{
		Door->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.0f, 0.0f, 0.0f)), 0.05));
	}
}

void AMSOpenDoor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{

		//FVector PawnLocation = OtherActor->GetActorLocation();
		//FVector Direction = GetActorLocation() - PawnLocation;
		//Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, GetActorRotation());
	//	if (Direction.X > 0.0f)
		//{
			RotateValue = 90.0f;
		//}
		//else
		//{
		//	RotateValue = -90.0f;
		//}

		if (GetWorld())
		{
			const auto GameMode = Cast<AMSGameMode>(GetWorld()->GetAuthGameMode());
			if (GameMode)
			{
				GameMode->SetPlayerOverlapping(true);
			}
		}

		const auto Player = Cast<AMSCharacter>(OtherActor);
		Player->OnKeyPressed.AddUObject(this, &AMSOpenDoor::OnOpenDoor);
	}
}

void AMSOpenDoor::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
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

void AMSOpenDoor::OnOpenDoor()
{
	Open = Open ? false : true;
	UGameplayStatics::PlaySound2D(GetWorld(), OpenDoorSound);
}