// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BossAIController.generated.h"

class UBossAttackData;

UCLASS()
class BOSSTEST_API ABossAIController : public AAIController
{
	GENERATED_BODY()

public:
    ABossAIController();

    // AI가 다음에 쓸 스킬을 고르는 핵심 함수
    UFUNCTION(BlueprintCallable, Category = "Boss AI")
    UBossAttackData* SelectAttackPattern(const TArray<UBossAttackData*>& AvailablePatterns);

    UFUNCTION(BlueprintCallable, Category = "Boss AI")
    void ResetCombo();

    UFUNCTION(BlueprintPure, Category = "Boss AI")
    bool IsComboActive() const;

    // 가장 최근에 사용한 패턴을 기억 (연속 사용 금지 체크용)
    UPROPERTY(VisibleInstanceOnly, Category = "Boss AI")
    UBossAttackData* LastUsedPattern;
	
};

