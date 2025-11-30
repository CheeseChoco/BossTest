#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ANS_AttackHitCheck.generated.h"

UCLASS()
class BOSSTEST_API UANS_AttackHitCheck : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

protected:
	// 에디터에서 선택할 공격 부위 (0:돌진, 1:오른손, 2:왼손)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify")
	int32 AttackPartIndex = 1;
};