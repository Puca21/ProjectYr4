// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Widgets/SCompoundWidget.h"
#include "SlateBasics.h"

/**
 * 
 */

//Lays out and controls the Main Menu UI for our tutorial
class PROJECT_API SMainMenuUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
	SLATE_END_ARGS()

	/*
	 * Contructs and lays out the Main Menu UI Widget
	 * args Argument structure that contains widget-specific setup information
	 */
	void Construct(const FArguments& InArgs);

	//Click handler for the Play Game button - Calls MenuHUD's PlayGameClicked() event.
	FReply PlayGameClicked();

	//Click handler for the Options button - Calls MenuHUD's OptionsClicked() event.
	FReply OptionsClicked();

	//Click handler for the Quit Game button - Calls MenuHUD's QuitGameClicked() event. 
	FReply QuitGameClicked();

	//Stores a weak reference to the HUD controlling this class
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;

	const struct FGlobalMenuStyle* MenuStyle;

};