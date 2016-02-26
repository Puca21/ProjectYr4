// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "Monster.h"
#include "PlayerCharacter.h"
#include "MeleeWeapon.h"

AMonster::AMonster(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Speed = 20;
	HitPoints = 20;
	BaseAttackDamage = 1;
	AttackTimeout = 1.5f;
	TimeSinceLastStrike = 0;

	SightSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SightSphere"));
	SightSphere->AttachTo(RootComponent);

	AttackRangeSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("AttackRangeSphere"));
	AttackRangeSphere->AttachTo(RootComponent);
}

void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//move the monster towards the player
	APlayerCharacter *avatar = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!avatar) return;

	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	
	float distanceToPlayer = toPlayer.Size();

	//If the player is not in the SightSphere of the monster, go back
	if (distanceToPlayer > SightSphere->GetScaledSphereRadius())
	{
		//if the player is out of sight the monster will not chnage
		return;
	}

	//Normalizes the vector
	toPlayer /= distanceToPlayer;
	//Actually move the monster towards the player
	AddMovementInput(toPlayer, Speed*DeltaTime);

	//Face the target
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0;
	RootComponent->SetWorldRotation(toPlayerRotation);
}

void AMonster::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	//instantiate the melee weapon
	if (BP_MeleeWeapon)
	{
		MeleeWeapon = GetWorld()->SpawnActor<AMeleeWeapon>(BP_MeleeWeapon, FVector(), FRotator());

		if (MeleeWeapon)
		{
			const USkeletalMeshSocket *socket = Mesh->GetSocketByName("RightHandSocket");
			socket->AttachActor(MeleeWeapon, Mesh);
		}
	}

}