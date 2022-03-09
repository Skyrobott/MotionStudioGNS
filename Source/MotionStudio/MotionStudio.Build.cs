// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MotionStudio : ModuleRules
{
	public MotionStudio(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", 
			"CoreUObject",
			"Engine",
			"InputCore",
			"Niagara",
			"PhysicsCore",
			"GameplayTasks",
			"NavigationSystem",
			"UMG",
			"MediaAssets"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		PublicIncludePaths.AddRange(new string[] {
		"MotionStudio/Public/Player",
		"MotionStudio/Public/Components",
		"MotionStudio/Public/Doors",
		"MotionStudio/Public/Lights",
		"MotionStudio/Public/UI",
		"MotionStudio/Public/Menu",
		"MotionStudio/Public/Menu/UI",
		"MotionStudio/Public/Saves"
		});
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
