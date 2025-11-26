// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BossTest : ModuleRules
{
	public BossTest(ReadOnlyTargetRules Target) : base(Target)
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
			"BossTest",
			"BossTest/Variant_Platforming",
			"BossTest/Variant_Platforming/Animation",
			"BossTest/Variant_Combat",
			"BossTest/Variant_Combat/AI",
			"BossTest/Variant_Combat/Animation",
			"BossTest/Variant_Combat/Gameplay",
			"BossTest/Variant_Combat/Interfaces",
			"BossTest/Variant_Combat/UI",
			"BossTest/Variant_SideScrolling",
			"BossTest/Variant_SideScrolling/AI",
			"BossTest/Variant_SideScrolling/Gameplay",
			"BossTest/Variant_SideScrolling/Interfaces",
			"BossTest/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
