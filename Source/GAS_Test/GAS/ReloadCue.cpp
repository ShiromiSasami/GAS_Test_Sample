// Fill out your copyright notice in the Description page of Project Settings.


#include "ReloadCue.h"
#include "PlayerAttributeSet.h"
#include "PlayerAbilitySystemComponent.h"
#include "GAS_Test/GAS_TestCharacter.h"
#include "NativeTags.h"

UReloadCue::UReloadCue()
{
    //�^�O�̕R�Â�
    //GameplayCueTag = FNativeTags::Get().Reload;
}

void UReloadCue::HandleGameplayCue(AActor* MyTarget, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters)
{
    Super::HandleGameplayCue(MyTarget, EventType, Parameters);

    if (EventType == EGameplayCueEvent::OnActive)
    {
        if (AGAS_TestCharacter* Character = Cast<AGAS_TestCharacter>(MyTarget))
        {
            UPlayerAbilitySystemComponent* ASC = Character->GetAbilitySystemComponent();
            //�����[�h
            int maxBulletCount = ASC->GetNumericAttribute(UPlayerAttributeSet::GetMaxBulletCountAttribute());
            ASC->ApplyModToAttribute(UPlayerAttributeSet::GetBulletCountAttribute(), EGameplayModOp::Override, maxBulletCount);
        }
    }
}
