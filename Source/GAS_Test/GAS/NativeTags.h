#pragma once

#include "GameplayTagContainer.h"

/**
 * ini�t�@�C���𐶐����Ȃ��A�l�C�e�B�u�ȃQ�[���v���C�^�O
 * �l�C�e�B�u�p�̃V���O���g��
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

