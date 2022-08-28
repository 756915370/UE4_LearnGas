// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "UObject/Object.h"
#include "GATargetActor.generated.h"

/**
 * 
 */
UCLASS()
class LEARNGAS_API AGATargetActor : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:
	AGATargetActor();

	virtual void StartTargeting(UGameplayAbility* Ability) override;
	virtual void ConfirmTargetingAndContinue() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn = true), Category="TargetActor")
	float TraceRange;

	bool LineTrace(FHitResult& HitResult);
};
