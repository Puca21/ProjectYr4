// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MeleeWeapon.generated.h"

class AMonster;

UCLASS()
class PROJECT_API AMeleeWeapon : public AActor
{
	GENERATED_UCLASS_BODY()

	//Amount of damage the melee weapon does
	UPROPERTY(EditAnywhere, Category = MeleeWeapon)
		float AttackDamage;
	
	//A list of things the melee weapon has already hit this swing
	//Ensures each thing the sword passes through only gets hit once
	TArray<AActor*> ThingsHit;

	//prevents damages from occuring in frames where the sword is not swinging
	bool Swinging;

	//Used to check if the actor holding the weapon is hitting himself
	AMonster *WeaponHolder;

	// bounding box that determines when melee weapon hit
	UPROPERTY(VisibleDefaultsOnly, Category = MeleeWeapon)
		UBoxComponent* ProxBox;

	UPROPERTY(VisibleDefaultsOnly, Category = MeleeWeapon)
		UStaticMeshComponent* Mesh;

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	//lets the class know what state the actor is in
	void Swing();
	void Rest();
};
