// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "GlobalMenuWidgetStyle.h"

void FGlobalMenuStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

const FName FGlobalMenuStyle::TypeName = TEXT("FGlobalMenuStyle");

const FName FGlobalMenuStyle::GetTypeName() const
{
	static const FName TypeName = TEXT("FGlobalMenuStyle");
	return TypeName;
}

const FGlobalMenuStyle& FGlobalMenuStyle::GetDefault()
{
	static FGlobalMenuStyle Default;
	return Default;
}

UGlobalMenuWidgetStyle::UGlobalMenuWidgetStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}



