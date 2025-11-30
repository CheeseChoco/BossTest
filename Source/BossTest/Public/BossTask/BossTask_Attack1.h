// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "BossTask_Attack1.generated.h"

UCLASS()
class BOSSTEST_API UBossTask_Attack1 : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()

public:
	UBossTask_Attack1(const FObjectInitializer& ObjectInitializer);

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;

protected:
	// ✅ 에디터에서 공격 몽타주를 지정할 수 있게 노출
	UPROPERTY(EditAnywhere, Category = "Parameter")
	UAnimMontage* AttackMontage;

	// 내부 변수: 몽타주가 끝났는지 체크용
	bool bIsMontagePlaying = false;
};