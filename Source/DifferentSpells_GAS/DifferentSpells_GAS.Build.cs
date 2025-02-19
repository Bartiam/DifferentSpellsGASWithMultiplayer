// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DifferentSpells_GAS : ModuleRules
{
	public DifferentSpells_GAS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
