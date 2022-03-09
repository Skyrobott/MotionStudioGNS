// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/MSCharacterMovementComponent.h"
#include "Lights/MSSwithActor.h"


AMSCharacter::AMSCharacter(const FObjectInitializer& ObjInit)
	: Super(ObjInit.SetDefaultSubobjectClass<UMSCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{

	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());
	CameraComponent->bUsePawnControlRotation = true;
}


void AMSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMSCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AMSCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &AMSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AMSCharacter::OnPressed);
}

void AMSCharacter::MoveForward(float Amount)
{
	IsMovingForward = Amount > 0.0f;
	if (Amount == 0.0f)
		return;
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AMSCharacter::MoveRight(float Amount)
{
	if (Amount == 0.0f)
		return;
	AddMovementInput(GetActorRightVector(), Amount);
}

void AMSCharacter::OnPressed()
{
	OnKeyPressed.Broadcast();
}
