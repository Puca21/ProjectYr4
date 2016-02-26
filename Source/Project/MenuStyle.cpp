// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "MenuStyle.h"
#include "SlateGameResources.h"

TSharedPtr<FSlateStyleSet> FMenuStyle::MenuStyleInstance = NULL;

void FMenuStyle::Initialize()
{
	if (!MenuStyleInstance.IsValid())
	{
		MenuStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MenuStyleInstance);
	}
}

void FMenuStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*MenuStyleInstance);
	ensure(MenuStyleInstance.IsUnique());
	MenuStyleInstance.Reset();
}

FName FMenuStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MenuStyle"));
	return StyleSetName;
}

TSharedRef<FSlateStyleSet> FMenuStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FMenuStyle::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");
	return StyleRef;
}

const ISlateStyle& FMenuStyle::Get()
{
	return *MenuStyleInstance;
}