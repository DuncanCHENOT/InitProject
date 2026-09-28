// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class InitProject : ModuleRules
{
	public InitProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"InitProject",
			"InitProject/Variant_Platforming",
			"InitProject/Variant_Platforming/Animation",
			"InitProject/Variant_Combat",
			"InitProject/Variant_Combat/AI",
			"InitProject/Variant_Combat/Animation",
			"InitProject/Variant_Combat/Gameplay",
			"InitProject/Variant_Combat/Interfaces",
			"InitProject/Variant_Combat/UI",
			"InitProject/Variant_SideScrolling",
			"InitProject/Variant_SideScrolling/AI",
			"InitProject/Variant_SideScrolling/Gameplay",
			"InitProject/Variant_SideScrolling/Interfaces",
			"InitProject/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
