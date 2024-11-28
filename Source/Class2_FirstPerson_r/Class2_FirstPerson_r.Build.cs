// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Class2_FirstPerson_r : ModuleRules
{
	public Class2_FirstPerson_r(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
