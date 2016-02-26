// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "FPSHUD.h"


AFPSHUD::AFPSHUD(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	//Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/crosshair.crosshair'"));
	CrosshairTex = CrosshairTexObj.Object;
}

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	//find the center of the canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	//offset by half the texture's dimensions so that the center of the texture aligns with the center of the canvas
	const FVector2D CrosshairDrawPosition((Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5f)),
		(Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));

	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);

	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f*pad;
		float x = 0.f, y = c*messageH;
		// black backing
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);
		// draw our message using the hudFont
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);
		// reduce lifetime by the time that passed since last frame.
		//DrawTexture(messages[c].tex, x, y, messageH, messageH, 0, 0, 1, 1);
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		// if the message's time is up, remove it
		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
}

void AFPSHUD::addMessage(Message msg)
{
	messages.Add(msg);
}

