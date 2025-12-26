// Copyright (C) 2025 R.Haris Nauman. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

// Forward declaration
class FCompositeLensSceneViewExtension;

class FCompositeLensFlareModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	void SetupLensFlare();
	void DestroyLensFlare();

public:
	TSharedPtr<FCompositeLensSceneViewExtension> SceneViewExtensionInstance;
};
