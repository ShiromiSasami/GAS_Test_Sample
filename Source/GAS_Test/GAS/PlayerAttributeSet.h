// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlayerAttributeSet.generated.h"

#define ATTRIBUTE(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_TEST_API UPlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UPlayerAttributeSet();

public:
	ATTRIBUTE(UPlayerAttributeSet, MaxBulletCount)
	ATTRIBUTE(UPlayerAttributeSet, BulletCount)

public:
	UPROPERTY(BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData MaxBulletCount;

	UPROPERTY(BlueprintReadOnly, Category = "Player Attributes")
	FGameplayAttributeData BulletCount;
};
