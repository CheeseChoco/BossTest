// Fill out your copyright notice in the Description page of Project Settings.

#include "BossTask/BossTask_Attack1.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
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
	AAIController* AIController = Cast<AAIController>(BossCharacter->GetController());

	// 방어 코드: 몽타주가 없으면 공격을 못함 -> 실패 처리
	if (!BossCharacter || !AttackMontage)
	{
		return EStateTreeRunStatus::Failed;
	}
	AIController->StopMovement();
	// 1. 공격 몽타주 재생!
	float Duration = BossCharacter->PlayAnimMontage(AttackMontage, PlayRate);

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
	if (bEnableRotation)
	{
		ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0);
		if (Player)
		{
			// A. 목표 회전값 계산 (보스 -> 플레이어 방향)
			FRotator TargetRot = UKismetMathLibrary::FindLookAtRotation(BossCharacter->GetActorLocation(), Player->GetActorLocation());

			// B. Z축(Yaw)만 회전해야 함 (보스가 하늘/땅을 보며 기울면 안 되니까)
			TargetRot = FRotator(0.0f, TargetRot.Yaw, 0.0f);

			// C. 부드럽게 회전 (RInterpTo)
			FRotator NewRot = FMath::RInterpTo(BossCharacter->GetActorRotation(), TargetRot, DeltaTime, RotationSpeed);

			// D. 적용
			BossCharacter->SetActorRotation(NewRot);
		}
	}

	return EStateTreeRunStatus::Running;
}