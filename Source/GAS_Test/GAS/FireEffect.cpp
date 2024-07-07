// Fill out your copyright notice in the Description page of Project Settings.


#include "FireEffect.h"
#include "PlayerAttributeSet.h"

UFireEffect::UFireEffect()
{
    DurationPolicy = EGameplayEffectDurationType::Instant;
    // BulletCount�����炷Modifier��ݒ�
    FGameplayModifierInfo ModifierInfo;
    ModifierInfo.Attribute = UPlayerAttributeSet::GetBulletCountAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Additive;
    ModifierInfo.ModifierMagnitude = FScalableFloat(-1.0f); // BulletCount��1���炷
    Modifiers.Add(ModifierInfo);
}
