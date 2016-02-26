// Fill out your copyright notice in the Description page of Project Settings.
/*
#include "Project.h"
#include "PlayerCharacterMovement.h"


// Sets default values for this component's properties
UPlayerCharacterMovement::UPlayerCharacterMovement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

float UPlayerCharacterMovement::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();

	const APlayerCharacter* PlayerCharacterOwner = Cast<APlayerCharacter>(PawnOwner);
	if (PlayerCharacterOwner)
	{
		if (PlayerCharacterOwner->IsTargeting())
		{
			MaxSpeed *= PlayerCharacterOwner->GetTargetingSpeedModifier();
		}
		if (PlayerCharacterOwner->IsRunning())
		{
			MaxSpeed *= PlayerCharacterOwner->GetRunningSpeedModifier();
		}
	}

	return MaxSpeed;
}
*/