// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBasics.h"
#include "GlobalMenuWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct FGlobalMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()
	//Stores a list of Brushes we are using into OutBrushes.
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;

	//Stores the TypeName for our widget style.
	static const FName TypeName;

	//Retrieves the type name for our global style, which will be used by our Style Set to load the right file.
	virtual const FName GetTypeName() const override;

	//Allows us to set default values for our various styles.
	static const FGlobalMenuStyle& GetDefault();

	//Style that define the appearance of all Menu Buttons.
	UPROPERTY(EditAnywhere, Category = Appearance)
		FButtonStyle MenuButtonStyle;

	//Style that defines the text on all of our Menu Buttons
	UPROPERTY(EditAnywhere, Category = Appearance)
		FTextBlockStyle MenuButtonTextStyle;

	//Style that defines the text of our menu title.
	UPROPERTY(EditAnywhere, Category = Appearance)
		FTextBlockStyle MenuTitleStyle;

};

//Provides a widget style container to allow us to edit properties in-editor
UCLASS(hidecategories=Object, MinimalAPI)
class UGlobalMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_UCLASS_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FGlobalMenuStyle MenuStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &MenuStyle );
	}
};
