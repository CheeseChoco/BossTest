// Fill out your copyright notice in the Description page of Project Settings.

#include "BossTask/BossTask_Attack1.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "StateTreeExecutionContext.h"

UBossTask_Attack1::UBossTask_Attack1(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bShouldCallTick = true; // 몽타주 끝나는 거 감시해야 함
}

EStateTreeRunStatus UBossTask_Attack1::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
	AActor* OwnerActor = Cast<AActor>(Context.GetOwner());
	ACharacter* BossCharacter = Cast<ACharacter>(OwnerActor);

	// 방어 코드: 몽타주가 없으면 공격을 못함 -> 실패 처리
	if (!BossCharacter || !AttackMontage)
	{
		return EStateTreeRunStatus::Failed;
	}

	// 1. 공격 몽타주 재생!
	float Duration = BossCharacter->PlayAnimMontage(AttackMontage);

	if (Duration > 0.0f)
	{
		bIsMontagePlaying = true;
		return EStateTreeRunStatus::Running; // 재생 시작됨
	}

	return EStateTreeRunStatus::Failed; // 재생 실패 (뭔가 꼬임)
}

EStateTreeRunStatus UBossTask_Attack1::Tick(FStateTreeExecutionContext& Context, const float DeltaTime)
{
	AActor* OwnerActor = Cast<AActor>(Context.GetOwner());
	ACharacter* BossCharacter = Cast<ACharacter>(OwnerActor);

	if (!BossCharacter) return EStateTreeRunStatus::Failed;

	// 2. 몽타주가 아직 재생 중인지 확인
	// (몽타주가 끝나면 PlayAnimMontage는 0.0을 리턴하거나, AnimInstance가 멈춤을 알림)
	// 가장 확실한 방법: 해당 몽타주가 지금 돌아가고 있니?
	UAnimInstance* AnimInstance = BossCharacter->GetMesh()->GetAnimInstance();
	if (AnimInstance && !AnimInstance->Montage_IsPlaying(AttackMontage))
	{
		// 재생이 멈췄다 = 공격 동작 끝났다!
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}