// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "NPC.generated.h"

UCLASS()
class PROJECT_API ANPC : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = NPCMessage)
		FString NpcMessage;

	UPROPERTY(EditAnywhere, Category = Collision)
		class USphereComponent* ProxSphere;

	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	UPROPERTY(EditAnywhere, Category = NPCMessage)
		FString name;

	UPROPERTY(EditAnywhere, Category = NPCMessage)
		UTexture2D* Face;
	
};
