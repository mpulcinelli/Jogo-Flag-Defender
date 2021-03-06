// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Flag_defender : ModuleRules
{
	public Flag_defender(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core",
                                                            "CoreUObject",
                                                            "Engine",
                                                            "InputCore",
                                                            "HeadMountedDisplay",
                                                            "PhysX",
                                                            "APEX",
                                                            "ApexDestruction",
                                                            "AIModule"});
	}
}
