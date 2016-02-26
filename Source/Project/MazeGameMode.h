// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MazeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMazeGameMode : public AGameMode
{
	GENERATED_BODY()

		AMazeGameMode(const FObjectInitializer& ObjectInitializer);

		virtual void StartPlay() override;
	
	
	
};
