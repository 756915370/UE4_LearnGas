// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

//定义ATTRIBUTE_ACCESSORS这个宏代替下面四个宏。下面四个分布含有获得Property、获得值，设置值，初始化的功能
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class LEARNGAS_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBaseAttributeSet();

	//Attributes for Health
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,Health)

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,MaxHealth)
	//Attribute for Mana

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttribute")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,Mana)

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttribute")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,MaxMana)
	
	//Attribute for Stamina
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttribute")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,Stamina)

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttribute")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,MaxStamina)

	//Attribute for Shield
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttribute")
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,Shield)

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttribute")
	FGameplayAttributeData MaxShield;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,MaxShield)

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
