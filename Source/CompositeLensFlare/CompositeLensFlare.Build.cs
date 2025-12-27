// Copyright Epic Games, Inc. All Rights Reserved.

using System.Collections.Generic;
using System.IO;
using UnrealBuildTool;

public class CompositeLensFlare : ModuleRules
{
	public CompositeLensFlare(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.Add(EngineDirectory + "/Source/Runtime/Renderer/Private");

		// Public dependencies
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "Renderer" });

		// Private dependencies
		PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "RenderCore", "Projects", "RHICore", "RHI" });

		// Fix for 5.6
		PrivateIncludePaths.Add(Path.Combine(GetModuleDirectory("Renderer"), ("Private")));
		PrivateIncludePaths.Add(Path.Combine(GetModuleDirectory("Renderer"), ("Internal")));
	}
}