#pragma once

#include "GameplayTagContainer.h"

/**
 * iniファイルを生成しない、ネイティブなゲームプレイタグ
 * ネイティブ用のシングルトン
 */

struct FNativeTags
{
private:
	static FNativeTags Instance;

public:
	static const FNativeTags& Get() 
	{ 
		if (!Instance.bIsInstantceCreated)[[unlikely]]
		{
			Instance.InitializeNativeGameplayTags();
			Instance.bIsInstantceCreated = true;
		}
		return Instance; 
	}
	
	FGameplayTag FireWait;
	FGameplayTag Hit;

	FGameplayTag Reload;
	
private:
	void InitializeNativeGameplayTags();
	
	bool bIsInstantceCreated = false;
};

