// Fill out your copyright notice in the Description page of Project Settings.


#include "FireEffect.h"
#include "PlayerAttributeSet.h"

UFireEffect::UFireEffect()
{
    DurationPolicy = EGameplayEffectDurationType::Instant;
    // BulletCountを減らすModifierを設定
    FGameplayModifierInfo ModifierInfo;
    ModifierInfo.Attribute = UPlayerAttributeSet::GetBulletCountAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Additive;
    ModifierInfo.ModifierMagnitude = FScalableFloat(-1.0f); // BulletCountを1減らす
    Modifiers.Add(ModifierInfo);
}
