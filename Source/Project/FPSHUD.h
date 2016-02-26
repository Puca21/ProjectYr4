// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"

struct Message
{
	FString message;
	float time;
	FColor color;
	UTexture2D* tex;
	Message()
	{
		//Set the default time
		time = 5.f;
		color = FColor::White;
	}
	Message(FString iMessage, float iTime, FColor iColor)
	{
		message = iMessage;
		time = iTime;
		color = iColor;
	}
};
/**
 * 
 */
UCLASS()
class PROJECT_API AFPSHUD : public AHUD
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = HUDFont)
	UFont* hudFont;

public:
	AFPSHUD(const FObjectInitializer& ObjectInitializer);

	/*Primary draw call for the HUD*/
	virtual void DrawHUD() override;

	TArray<Message> messages;

	void addMessage(Message msg);
	
private:
	/*Crosshair asset*/
	UTexture2D* CrosshairTex;
};
