using UnrealBuildTool;

public class BoltUnrealSDK : ModuleRules
{
    public BoltUnrealSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "HTTP", "WebBrowser" }
        );
    }
}
