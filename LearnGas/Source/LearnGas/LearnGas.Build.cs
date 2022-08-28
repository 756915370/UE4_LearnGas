// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearnGas : ModuleRules
{
	public LearnGas(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTags", "GameplayAbilities","GameplayTasks"
		});
	}
}