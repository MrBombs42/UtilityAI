// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GymSimulator : ModuleRules
{
	public GymSimulator(ReadOnlyTargetRules Target) : base(Target)
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
			"GymSimulator",
			"GymSimulator/Variant_Platforming",
			"GymSimulator/Variant_Platforming/Animation",
			"GymSimulator/Variant_Combat",
			"GymSimulator/Variant_Combat/AI",
			"GymSimulator/Variant_Combat/Animation",
			"GymSimulator/Variant_Combat/Gameplay",
			"GymSimulator/Variant_Combat/Interfaces",
			"GymSimulator/Variant_Combat/UI",
			"GymSimulator/Variant_SideScrolling",
			"GymSimulator/Variant_SideScrolling/AI",
			"GymSimulator/Variant_SideScrolling/Gameplay",
			"GymSimulator/Variant_SideScrolling/Interfaces",
			"GymSimulator/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
