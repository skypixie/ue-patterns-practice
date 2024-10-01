// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPPMiddlePractice : ModuleRules
{
	public CPPMiddlePractice(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
