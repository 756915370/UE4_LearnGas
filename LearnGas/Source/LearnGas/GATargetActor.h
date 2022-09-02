// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "UObject/Object.h"
#include "GATargetActor.generated.h"

USTRUCT(BlueprintType)
struct FMyStruct
{
	GENERATED_BODY()
	int Number;
	FString Str;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMyCustomDelegate, const FMyStruct&, Data);

/**
 * 
 */
UCLASS()
class LEARNGAS_API AGATargetActor : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:
	AGATargetActor();

	UPROPERTY(BlueprintAssignable)
	FMyCustomDelegate MyDelegate;

	//加了BlueprintInternalUseOnly后蓝图就不能看到了。像AbilityTask_WaitTargetData就是加了这个宏。然后在UK2Node_LatentGameplayTaskCall绘制UFUNCTION。
	UFUNCTION(BlueprintCallable,meta=(BlueprintInternalUseOnly = "true"))
	static AGATargetActor* NewTargetActorTest();
	
	virtual void StartTargeting(UGameplayAbility* Ability) override;
	virtual void ConfirmTargetingAndContinue() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn = true), Category="TargetActor")
	float TraceRange;

	bool LineTrace(FHitResult& HitResult);
};
