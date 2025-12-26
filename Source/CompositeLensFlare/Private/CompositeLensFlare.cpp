// Copyright (C) 2025 R.Haris Nauman. All Rights Reserved.

#include "CompositeLensFlare.h"
#include "CompositeLensSceneViewExtension.h"
#include "SceneViewExtension.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FCompositeLensFlareModule"

void FCompositeLensFlareModule::StartupModule()
{
	// Register shader directory
	FString BaseDir = IPluginManager::Get().FindPlugin(TEXT("CompositeLensFlare"))->GetBaseDir();
	const FString PluginShaderDir = FPaths::Combine(BaseDir, TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/CompositeLensFlare"), PluginShaderDir);

	// Setup lens flare
	if (GEngine && GEngine->IsInitialized())
	{
		SetupLensFlare();
	}
	else
	{
		FCoreDelegates::OnPostEngineInit.AddRaw(this, &FCompositeLensFlareModule::SetupLensFlare);
	}
	
}

void FCompositeLensFlareModule::ShutdownModule()
{
	FCoreDelegates::OnPostEngineInit.RemoveAll(this);
	DestroyLensFlare();
}

void FCompositeLensFlareModule::SetupLensFlare()
{
	// Remove delegate if it was registered
	FCoreDelegates::OnPostEngineInit.RemoveAll(this);

	if (!SceneViewExtensionInstance.IsValid())
	{
		SceneViewExtensionInstance = FSceneViewExtensions::NewExtension<FCompositeLensSceneViewExtension>();
		SceneViewExtensionInstance->Initialize();
	}
}

void FCompositeLensFlareModule::DestroyLensFlare()
{
	if (SceneViewExtensionInstance.IsValid())
	{
		SceneViewExtensionInstance.Reset();
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCompositeLensFlareModule, CompositeLensFlare)