// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "SMainMenuUI.h"
#include "SlateOptMacros.h"
#include "GlobalMenuWidgetStyle.h"
#include "MenuStyle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuUI::Construct(const FArguments& args)
{
	MainMenuHUD = args._MainMenuHUD;
	MenuStyle = &FMenuStyle::Get().GetWidgetStyle<FGlobalMenuStyle>("Global");
	
	ChildSlot
	[
				SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				[
						SNew(STextBlock)
						.TextStyle(&MenuStyle->MenuTitleStyle)
						.Text(FText::FromString("Main Menu"))
				]
				+ SOverlay::Slot()
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Bottom)
					[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
									SNew(SButton)
									.ButtonStyle(&MenuStyle->MenuButtonStyle)
									.TextStyle(&MenuStyle->MenuButtonTextStyle)
									.Text(FText::FromString("Play Game"))
									.OnClicked(this, &SMainMenuUI::PlayGameClicked)
							]
							+ SVerticalBox::Slot()
									[
											SNew(SButton)
											.ButtonStyle(&MenuStyle->MenuButtonStyle)
											.TextStyle(&MenuStyle->MenuButtonTextStyle)
											.Text(FText::FromString("Quit Game"))
											.OnClicked(this, &SMainMenuUI::QuitGameClicked)
									]
					]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMainMenuUI::PlayGameClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("PlayGameClicked"));
	}

	return FReply::Handled();
}

FReply SMainMenuUI::QuitGameClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("QuitGameClicked"));
	}

	return FReply::Handled();
}

