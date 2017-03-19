// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class ReplicatedVehicle : ModuleRules
	{
		public ReplicatedVehicle(TargetInfo Target)
		{
            PublicIncludePaths.Add("ReplicatedVehicle/Public");
            PrivateIncludePaths.Add("ReplicatedVehicle/Private");

            PublicDependencyModuleNames.AddRange(
				new string[]
				{
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "AnimGraphRuntime",
                    "PhysX",
                    "APEX",
                    "PhysXVehicles",
                    "PhysXVehicleLib"
                }
			);
		}
	}
}