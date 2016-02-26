// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "MazeGameMode.h"
#include "Engine.h"
#include "PlayerCharacter.h"
#include "FPSHUD.h"

AMazeGameMode::AMazeGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//set default pawn class to out BluePrints Character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn '/Game/Characters/BP_PlayerCharacter.BP_PlayerCharacter_C'"));

	if (PlayerPawnObject.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}

	HUDClass = AFPSHUD::StaticClass();

}

void AMazeGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("A-MAZE-ING\n HUE HUE HUE\n\n"));
	}
}


