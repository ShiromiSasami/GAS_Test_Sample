// Fill out your copyright notice in the Description page of Project Settings.


#include "FireEffect.h"
#include "PlayerAttributeSet.h"

UFireEffect::UFireEffect()
{
    DurationPolicy = EGameplayEffectDurationType::Instant;
    // BulletCountÇå∏ÇÁÇ∑ModifierÇê›íË
    FGameplayModifierInfo ModifierInfo;
    ModifierInfo.Attribute = UPlayerAttributeSet::GetBulletCountAttribute();
    ModifierInfo.ModifierOp = EGameplayModOp::Additive;
    ModifierInfo.ModifierMagnitude = FScalableFloat(-1.0f); // BulletCountÇ1å∏ÇÁÇ∑
    Modifiers.Add(ModifierInfo);
}
