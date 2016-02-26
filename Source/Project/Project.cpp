// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "MenuStyle.h"

//Custom implementation of the Default Game Module.
class FProjectGameModule : public FDefaultGameModuleImpl
{
	/* Called whenever the module is starting up. In here, we unregister any style sets
	 * sharing out style set's name, then initialize our style set.
	 */
	virtual void StartupModule() override
	{
		//Hot reload hack
		FSlateStyleRegistry::UnRegisterSlateStyle(FMenuStyle::GetStyleSetName());
		FMenuStyle::Initialize();
	}

	virtual void ShutdownModule() override
	{
		FMenuStyle::Shutdown();
	}
};


IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Project, "Project" );
