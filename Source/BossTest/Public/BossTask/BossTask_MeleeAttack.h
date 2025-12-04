// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "BossTask/BossAttackData.h"
#include "BossTask_MeleeAttack.generated.h"



UCLASS()
class BOSSTEST_API UBossTask_MeleeAttack : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()

public:
	UBossTask_MeleeAttack(const FObjectInitializer& ObjectInitializer);

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;

protected:
	// ✅ 에디터에서 공격 몽타주를 지정할 수 있게 노출
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	class UBossAttackData* AttackData;

	// 내부 변수: 몽타주가 끝났는지 체크용
	bool bIsMontagePlaying = false;

	// --- 회전 관련 옵션은 AI 행동(Task)의 영역이라 남겨둬도 좋습니다 ---

	// 공격 중에 회전할 것인가?
	UPROPERTY(EditAnywhere, Category = "Parameter")
	bool bEnableRotation = true;

	// 회전 속도
	UPROPERTY(EditAnywhere, Category = "Parameter")
	float RotationSpeed = 5.0f;
};