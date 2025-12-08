// Fill out your copyright notice in the Description page of Project Settings.


#include "BossTask/BossTask_Takedown.h"
#include "BossTask/BossCharacter.h"
#include "BossTask/BossAttackData.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "StateTreeExecutionContext.h"
#include "DrawDebugHelpers.h"

// ... (ExecuteTask, TickTask 등은 동일하므로 생략, 변수 접근만 바뀜) ...

EStateTreeRunStatus UBossTask_Takedown::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    // [중요] 부모 클래스 로직 실행 (블루프린트 노드 호환성 위해 필수)
    Super::EnterState(Context, Transition);

    // Context Owner 가져오기
    AActor* OwnerActor = Cast<AActor>(Context.GetOwner());
    BossCharacter = Cast<ACharacter>(OwnerActor);

    if (!BossCharacter || !Montage_Start)
    {
        return EStateTreeRunStatus::Failed;
    }

    UAnimInstance* AnimInst = BossCharacter->GetMesh()->GetAnimInstance();
    if (!AnimInst) return EStateTreeRunStatus::Failed;

    // [1단계] Start 몽타주 재생
    InternalState = ETakedownState::Preparing;

    float Duration = AnimInst->Montage_Play(Montage_Start);
    if (Duration > 0.f)
    {
        FOnMontageEnded EndDelegate;
        EndDelegate.BindUObject(this, &UBossTask_Takedown::OnStartMontageEnded);
        AnimInst->Montage_SetEndDelegate(EndDelegate, Montage_Start);
    }
    else
    {
        // 몽타주 재생 실패 시 바로 다음 단계로
        OnStartMontageEnded(Montage_Start, false);
    }

    return EStateTreeRunStatus::Running;
}

void UBossTask_Takedown::OnStartMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
    if (bInterrupted || InternalState != ETakedownState::Preparing) return;

    InternalState = ETakedownState::Jumping;

    // 1. 점프 계산 및 실행
    PerformJumpLogic();

    // 2. Loop 몽타주 재생
    if (UAnimInstance* AnimInst = BossCharacter->GetMesh()->GetAnimInstance())
    {
        if (Montage_Loop) AnimInst->Montage_Play(Montage_Loop);
    }

    // 3. 착지 델리게이트 바인딩
    BossCharacter->LandedDelegate.AddDynamic(this, &UBossTask_Takedown::OnCharacterLanded);
}

void UBossTask_Takedown::PerformJumpLogic()
{
    if (!BossCharacter) return;

    ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(BossCharacter->GetWorld(), 0);
    if (!PlayerCharacter) return;

    FVector StartLoc = BossCharacter->GetActorLocation();
    FVector TargetLoc = PlayerCharacter->GetActorLocation();
    FVector LaunchVel;

    // 중력을 좀 더 세게 적용 (빠른 낙하 연출)
    float GravityZ = BossCharacter->GetCharacterMovement()->GetGravityZ();
    BossCharacter->GetCharacterMovement()->GravityScale = 2.0f;

    // [수정됨] 매개변수 구조체 선언 및 초기화
    // 생성자 순서: (WorldContextObject, StartLocation, EndLocation)
    UGameplayStatics::FSuggestProjectileVelocityParameters Params(
        StartLoc,
        TargetLoc
    );

    // [옵션 설정] 기존 함수에서 뒤에 나열하던 인자들을 여기서 설정합니다.
    Params.OverrideGravityZ = GravityZ;
    Params.TraceOption = ESuggestProjVelocityTraceOption::DoNotTrace;
    Params.bFavorHighArc = false; // 기존의 bHighArc = false에 해당 (낮은 탄도 선호)
    Params.CollisionRadius = 0.f;

    // [함수 호출]
    // 첫 번째 인자: WorldContext (보통 this나 Character)
    // 두 번째 인자: 결과값을 받을 변수 (Reference)
    // 세 번째 인자: 위에서 설정한 파라미터 구조체
    bool bCalculated = UGameplayStatics::SuggestProjectileVelocity(BossCharacter, LaunchVel, Params);

    if (bCalculated)
    {
        BossCharacter->LaunchCharacter(LaunchVel, true, true);
    }
    else
    {
        // 계산 실패 시(천장 등) 그냥 플레이어 방향으로 밀어버림 (fallback)
        FVector Dir = (TargetLoc - StartLoc).GetSafeNormal();
        Dir.Z = 0.5f; // 약간 위로
        BossCharacter->LaunchCharacter(Dir * 1000.f, true, true);
    }
}
void UBossTask_Takedown::OnCharacterLanded(const FHitResult& Hit)
{
    if (InternalState != ETakedownState::Jumping) return;

    // 델리게이트 해제
    BossCharacter->LandedDelegate.RemoveDynamic(this, &UBossTask_Takedown::OnCharacterLanded);

    InternalState = ETakedownState::Recovering;

    // 물리 복구
    BossCharacter->GetCharacterMovement()->GravityScale = 1.0f;
    BossCharacter->GetCharacterMovement()->StopMovementImmediately();

    // 공격 판정
    PerformImpactLogic();

    // Land 몽타주 재생
    UAnimInstance* AnimInst = BossCharacter->GetMesh()->GetAnimInstance();
    if (AnimInst && Montage_Land)
    {
        AnimInst->Montage_Play(Montage_Land);

        FOnMontageEnded EndDelegate;
        EndDelegate.BindUObject(this, &UBossTask_Takedown::OnLandMontageEnded);
        AnimInst->Montage_SetEndDelegate(EndDelegate, Montage_Land);
    }
    else
    {
        InternalState = ETakedownState::Finished;
    }
}

void UBossTask_Takedown::PerformImpactLogic()
{
    // 여기에 OverlapMultiByChannel 등 데미지 로직 구현
    // DrawDebugSphere(BossCharacter->GetWorld(), BossCharacter->GetActorLocation(), 300.f, 32, FColor::Red, false, 2.0f);
}

void UBossTask_Takedown::OnLandMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
    InternalState = ETakedownState::Finished;
}

EStateTreeRunStatus UBossTask_Takedown::Tick(FStateTreeExecutionContext& Context, const float DeltaTime)
{
    // [중요] 부모 Tick 호출
    Super::Tick(Context, DeltaTime);

    if (InternalState == ETakedownState::Finished)
    {
        return EStateTreeRunStatus::Succeeded;
    }
    return EStateTreeRunStatus::Running;
}

void UBossTask_Takedown::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    // [중요] 부모 ExitState 호출
    Super::ExitState(Context, Transition);

    if (BossCharacter)
    {
        // 안전장치: 델리게이트 해제
        BossCharacter->LandedDelegate.RemoveDynamic(this, &UBossTask_Takedown::OnCharacterLanded);

        // 중력 복구
        if (BossCharacter->GetCharacterMovement())
        {
            BossCharacter->GetCharacterMovement()->GravityScale = 1.0f;
        }

        // 재생 중인 몽타주 정리
        if (UAnimInstance* AnimInst = BossCharacter->GetMesh()->GetAnimInstance())
        {
            if (AnimInst->Montage_IsPlaying(Montage_Start)) AnimInst->Montage_Stop(0.2f, Montage_Start);
            if (AnimInst->Montage_IsPlaying(Montage_Loop)) AnimInst->Montage_Stop(0.2f, Montage_Loop);
            if (AnimInst->Montage_IsPlaying(Montage_Land)) AnimInst->Montage_Stop(0.2f, Montage_Land);
        }
    }
}