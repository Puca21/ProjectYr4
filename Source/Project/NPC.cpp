// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "NPC.h"
#include "PlayerCharacter.h"
#include "FPSHUD.h"


ANPC::ANPC(const FObjectInitializer& ObjectInitializer) 
	:Super(ObjectInitializer)
{
	ProxSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("Proximity Sphere"));
	ProxSphere->AttachTo(RootComponent);
	ProxSphere->SetSphereRadius(100.f);
	// Code to make ANPC::Prox() run when this proximity sphere overlaps another actor.
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::Prox);
	//default message, can be edited in Blueprints
	NpcMessage = "Walk into the portal to be teleported to a random maze!";
}

void ANPC::Prox_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// if the overlapped actor is not the player,
	// you should just simply return from the function
	if (Cast<APlayerCharacter>(OtherActor) == nullptr)
	{
		return;
	}
	APlayerController* PController = GetWorld() ->GetFirstPlayerController();
	if (PController)
	{
		AFPSHUD * hud = Cast<AFPSHUD>(PController->GetHUD());
		hud->addMessage(Message(/*name + FString(": ") +*/ NpcMessage, 5.f, FColor::White));
		
	}
}