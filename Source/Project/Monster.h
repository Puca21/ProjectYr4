// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Monster.generated.h"

UCLASS()
class PROJECT_API AMonster : public ACharacter
{
	GENERATED_BODY()
public:
	AMonster(const FObjectInitializer& ObjectInitializer);

	//speed of the monster
	UPROPERTY(EditAnywhere, Category = MonsterProperties)
		float Speed;

	//hitpoints the monster has
	UPROPERTY(EditAnywhere, Category = MonsterProperties)
		float HitPoints;

	//Amount of damage attacks do
	UPROPERTY(EditAnywhere, Category = MonsterProperties)
		float BaseAttackDamage;
	
	//Time between attacks
	UPROPERTY(EditAnywhere, Category = MonsterProperties)
		float AttackTimeout;

	//Time since monsters last strike
	UPROPERTY(EditAnywhere, Category = MonsterProperties)
		float TimeSinceLastStrike;

	//Range for sight
	UPROPERTY(VisibleDefaultsOnly, Category = Collision)
		USphereComponent* SightSphere;

	//Range for Monsters Attack
	UPROPERTY(VisibleDefaultsOnly, Category = Collision)
		USphereComponent* AttackRangeSphere;

	//The MeleeWeapon class the monster uses
	UPROPERTY(EditAnywhere, Category = MonsterProperties)
		UClass* BP_MeleeWeapon;

	//The MeleeWeapon Instance
	AActor* MeleeWeapon;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	inline bool isInSightRange(float d)
	{
		return d < SightSphere->GetScaledSphereRadius();
	}

	inline bool  isInAttackRange(float d)
	{
		return d < AttackRangeSphere->GetScaledSphereRadius();
	}

	virtual void PostInitializeComponents() override;
		
};

