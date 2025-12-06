#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BossAttackData.generated.h"

// 어떤 콜라이더를 쓸지 결정하는 열거형
UENUM(BlueprintType)
enum class EAttackHitboxType : uint8
{
    None,
    RightHand,
    LeftHand,
    BodyCharge,
    Slam
};


/**
 * 공격 하나에 대한 모든 정보를 담는 데이터 통
 */
UCLASS(BlueprintType)
class BOSSTEST_API UBossAttackData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    // 1. 애니메이션
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
    UAnimMontage* Montage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
    float PlayRate = 1.0f;

    //피격 판정 설정 (다중 선택 가능)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Collision")
    TArray<EAttackHitboxType> ActiveHitboxes;

    // 3. 연출 (VFX / SFX)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
    UParticleSystem* AttackVFX; // 공격 시 터지는 이펙트

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
    FName VFXSocketName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
    USoundBase* AttackSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FX")
    TSubclassOf<UCameraShakeBase> CameraShake;

    // [추가 1] 쏠 투사체 블루프린트 (여기에 BP_BossBullet을 넣게 됨)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    TSubclassOf<AActor> ProjectileClass;

    // [추가 2] 총알이 나갈 소켓 이름 (예: "Muzzle_01")
    // 이펙트 소켓이랑 다를 수 있어서 따로 파는 게 좋습니다.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    FName MuzzleSocketName;
    // (필요하면 데칼 정보 등 추가)


    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
    float FRand = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
    float CooldownTime = 0.0f; // 0이면 쿨타임 없음
};