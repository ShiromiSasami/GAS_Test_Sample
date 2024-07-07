#include "NativeTags.h"
#include "GameplayTagsManager.h"

FNativeTags FNativeTags::Instance;

void FNativeTags::InitializeNativeGameplayTags()
{
	UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
	Instance.FireWait = Manager.AddNativeGameplayTag(FName("Player.FireWait"), FString("wait until ready to fire"));
	Instance.Hit = Manager.AddNativeGameplayTag(FName("Projectile.Hit"), FString("projectile contact to actor"));

	Instance.Reload = Manager.AddNativeGameplayTag(FName("GameplayCue.Player.Reload"), FString("replenishment of ammunition"));
}
