// Fill out your copyright notice in the Description page of Project Settings.


#include "GEExecMelee.h"
#include "BaseAttributeSet.h"

struct DamageCapture
{
	//声明一个FProperty和FGameplayEffectAttributeCaptureDefinition
	DECLARE_ATTRIBUTE_CAPTUREDEF(Shield)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health)

	DamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, Shield, Target, true)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, Health, Target, true)
	}
};

static DamageCapture& GetDamageCapture()
{
	static DamageCapture DamageCaptureVar;
	return DamageCaptureVar;
}

UGEExecMelee::UGEExecMelee()
{
	RelevantAttributesToCapture.Add(GetDamageCapture().ShieldDef);
	RelevantAttributesToCapture.Add(GetDamageCapture().HealthDef);
	ValidTransientAggregatorIdentifiers.AddTag(FGameplayTag::RequestGameplayTag("char.calc.damage.melee"));
}

void UGEExecMelee::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
                                          FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	float OutHealth;
	float OutShield;

	float ShieldMagnitude = 0.0f;
	float HealthMagnitude = 0.0f;
	float AttackDamage = 0.0f;

	//根据FGameplayEffectAttributeCaptureDefinition获得数值
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().ShieldDef,
	                                                           FAggregatorEvaluateParameters(), ShieldMagnitude);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().HealthDef,
	                                                           FAggregatorEvaluateParameters(), HealthMagnitude);
	//根据Tag获得数值
	ExecutionParams.AttemptCalculateTransientAggregatorMagnitude(
		FGameplayTag::RequestGameplayTag("char.calc.damage.melee"), FAggregatorEvaluateParameters(), AttackDamage);

	OutShield = ShieldMagnitude - AttackDamage;
	if (OutShield < 0)
	{
		OutHealth = HealthMagnitude - fabs(OutShield);
		OutShield = 0;
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetDamageCapture().ShieldProperty, EGameplayModOp::Override, OutShield));
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetDamageCapture().HealthProperty, EGameplayModOp::Override, OutHealth));
	}
	else
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetDamageCapture().ShieldProperty, EGameplayModOp::Override, OutShield));
	}
}
