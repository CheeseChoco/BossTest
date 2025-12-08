// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "BossTask_Takedown.generated.h"

/**
 * 
 */
UCLASS()
class BOSSTEST_API UBossTask_Takedown : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()


public:
	UBossTask_Takedown();
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;



private:
	// 내부 로직 진행 상태
	enum class ETakedownState
	{
		Preparing,  // Start 몽타주
		Jumping,    // Loop 몽타주 (공중)
		Recovering, // Land 몽타주 (착지)
		Finished    // 완료
	};

	void PerformJumpLogic();
	void PerformImpactLogic();

	// --- 설정 변수 (에디터에서 할당) ---
	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* Montage_Start;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* Montage_Loop;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* Montage_Land;


	// --- 델리게이트 함수 ---
	UFUNCTION()
	void OnStartMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnCharacterLanded(const FHitResult& Hit);

	UFUNCTION()
	void OnLandMontageEnded(UAnimMontage* Montage, bool bInterrupted);


	ETakedownState InternalState;
	FDelegateHandle LandedDelegateHandle;

	UPROPERTY(Transient)
	TObjectPtr<ACharacter> BossCharacter;

	//// 내부 동작 함수들
	//void StartJump();
	//void StartHover();
	//void StartSlam();
	//void OnLanded();
};
