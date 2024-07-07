// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAS_TestTarget : TargetRules
{
	public GAS_TestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("GAS_Test");
	}
}
