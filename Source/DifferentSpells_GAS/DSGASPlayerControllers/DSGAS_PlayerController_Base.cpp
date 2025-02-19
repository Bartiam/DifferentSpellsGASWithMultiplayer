// Fill out your copyright notice in the Description page of Project Settings.


#include "DSGAS_PlayerController_Base.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "../DSGASCharacters/DifferentSpells_GASCharacter.h"

void ADSGAS_PlayerController_Base::BeginPlay()
{
	Super::BeginPlay();

	CurrentCharacter = Cast<ADifferentSpells_GASCharacter>(GetPawn());

	SetInputMode(InputGameOnly);
	SetShowMouseCursor(false);

	if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		SubSystem->AddMappingContext(MappingContext, 0);
	}
}

void ADSGAS_PlayerController_Base::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Bind move
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADSGAS_PlayerController_Base::MoveCharacter);
		// Bind Look
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADSGAS_PlayerController_Base::LookCharacter);
		// Bind jump
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ADSGAS_PlayerController_Base::JumpCharacter);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ADSGAS_PlayerController_Base::StopJumpCharacter);
	}
}

void ADSGAS_PlayerController_Base::MoveCharacter(const FInputActionValue& Value)
{
	FVector2D MoveVector = Value.Get<FVector2D>();

	if (IsValid(CurrentCharacter))
	{
		const FRotator RotationYaw = FRotator(0.f, GetControlRotation().Yaw, 0.f);

		const FVector ForwardDirection = FRotationMatrix(RotationYaw).GetUnitAxis(EAxis::X);

		const FVector RightDirection = FRotationMatrix(RotationYaw).GetUnitAxis(EAxis::Y);

		CurrentCharacter->AddMovementInput(ForwardDirection, MoveVector.Y);
		CurrentCharacter->AddMovementInput(RightDirection, MoveVector.X);
	}
}

void ADSGAS_PlayerController_Base::JumpCharacter()
{
	CurrentCharacter->Jump();
}

void ADSGAS_PlayerController_Base::StopJumpCharacter()
{
	CurrentCharacter->StopJumping();
}

void ADSGAS_PlayerController_Base::LookCharacter(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (IsValid(CurrentCharacter))
	{
		AddYawInput(LookAxisVector.X);
		AddPitchInput(LookAxisVector.Y);
	}
}
