// Fill out your copyright notice in the Description page of Project Settings.


#include "BossTask/BossAIController.h"
#include "BossTask/BossAttackData.h" // 경로 확인 필요
#include "BossTask/BossCharacter.h"  // HP 확인용
#include "Bosstest.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

ABossAIController::ABossAIController()
{
    LastUsedPattern = nullptr;
}

void ABossAIController::ResetCombo()
{
    // 콤보 기억 삭제 -> 다음 선택 때는 '시동기'부터 다시 찾게 됨
    LastUsedPattern = nullptr;
}

bool ABossAIController::IsComboActive() const
{
    // 기억하고 있는 패턴이 있다면 콤보 중인 것으로 간주
    return LastUsedPattern != nullptr;
}

UBossAttackData* ABossAIController::SelectAttackPattern(const TArray<UBossAttackData*>& Candidates)
{
    //UE_LOG(LogBossTest, Warning, TEXT("AI Select: %d"), Candidates.Num());
    // 0. 후보 없으면 탈락
    if (Candidates.Num() == 0) return nullptr;

    APawn* OwnerPawn = GetPawn();
    ABossCharacter* Boss = Cast<ABossCharacter>(OwnerPawn);
    // (수정) GetTarget() 대신 플레이어 찾기
    AActor* Target = UGameplayStatics::GetPlayerCharacter(this, 0);

    if (!Boss || !Target) return nullptr;

    // 1. 상황 데이터 (거리, 각도)
    float Dist = FVector::Distance(Boss->GetActorLocation(), Target->GetActorLocation());

    FVector ToTarget = (Target->GetActorLocation() - Boss->GetActorLocation()).GetSafeNormal();
    float Dot = FVector::DotProduct(Boss->GetActorForwardVector(), ToTarget);
    float Angle = FMath::RadiansToDegrees(FMath::Acos(Dot));

    FVector BossForward = Boss->GetActorForwardVector();
    FVector BossRight = Boss->GetActorRightVector();

    // 2. [추가] 좌우 판별 (Right Vector 내적)
    // 0보다 크면 오른쪽, 작으면 왼쪽
    float RightDot = FVector::DotProduct(BossRight, ToTarget);

    // 2. 필터링 (조건 체크)
    TArray<UBossAttackData*> ValidPool;
    float TotalWeight = 0.0f;

    for (UBossAttackData* Data : Candidates)
    {
        if (!Data) continue;

        // 거리/각도 조건 안 맞으면 탈락
        if (Dist < Data->MinRange || Dist > Data->MaxRange) continue;
        if (Angle > Data->RequiredHitAngle) continue;
        //좌 우측 체크
        if (Data->RequiredSide == ETargetSideRequirement::Left && RightDot > 0.0f) continue;
        if (Data->RequiredSide == ETargetSideRequirement::Right && RightDot < 0.0f) continue;

        ValidPool.Add(Data);
        TotalWeight += Data->SelectionWeight;
    }

    //UE_LOG(LogBossTest, Warning, TEXT("AI Select: final %d"), ValidPool.Num());

    // 3. 가중치 랜덤 (Weighted Random)
    if (ValidPool.Num() == 0) return nullptr;

    float RandomPoint = FMath::FRandRange(0.0f, TotalWeight);
    float CurrentSum = 0.0f;

    for (UBossAttackData* Data : ValidPool)
    {
        CurrentSum += Data->SelectionWeight;
        if (RandomPoint <= CurrentSum)
        {
            LastUsedPattern = Data; // 선택 기억
            return Data;
        }
    }

    LastUsedPattern = ValidPool.Last();
    return ValidPool.Last();
}