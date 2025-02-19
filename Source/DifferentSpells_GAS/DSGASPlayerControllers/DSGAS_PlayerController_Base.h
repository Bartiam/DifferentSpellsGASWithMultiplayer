// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DSGAS_PlayerController_Base.generated.h"

class UInputAction;
struct FInputActionValue;

UCLASS()
class DIFFERENTSPELLS_GAS_API ADSGAS_PlayerController_Base : public APlayerController
{
	GENERATED_BODY()
	
protected: // Protected variables

	/* == Input actions and mapping context for movement character == */

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* MappingContext = nullptr;

	/* == Input actions and mapping context for movement character == */

protected: // Protected funtions

	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;

private: // Private variables

	UPROPERTY()
	class ADifferentSpells_GASCharacter* CurrentCharacter = nullptr;

	FInputModeGameOnly InputGameOnly;

private: // Private functions

	UFUNCTION()
	void MoveCharacter(const FInputActionValue& Value);

	UFUNCTION()
	void JumpCharacter();

	UFUNCTION()
	void StopJumpCharacter();

	UFUNCTION()
	void LookCharacter(const FInputActionValue& Value);
};
