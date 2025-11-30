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

	UPROPERTY(EditAnywhere, Category = "Parameter")
	float DamageAmount = 10.0f;

	// ✅ [추가 1] 공격 속도 배율 (1.0 = 정속, 1.5 = 1.5배 빠름)
	UPROPERTY(EditAnywhere, Category = "Parameter")
	float PlayRate = 1.5f;

	// ✅ [추가 2] 공격 중에 회전할 것인가?
	UPROPERTY(EditAnywhere, Category = "Parameter")
	bool bEnableRotation = true;

	// ✅ [추가 3] 회전 속도 (클수록 빨리 돔, 보통 5.0 ~ 10.0 추천)
	UPROPERTY(EditAnywhere, Category = "Parameter")
	float RotationSpeed = 5.0f;
};