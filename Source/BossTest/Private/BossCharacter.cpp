// Fill out your copyright notice in the Description page of Project Settings.


#include "BossCharacter.h"

// Sets default values
ABossCharacter::ABossCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	bUseControllerRotationYaw = false;

    // 1. 오른손 박스
    RightFistBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RightFistBox"));
    RightFistBox->SetupAttachment(GetMesh(), TEXT("RightHandSocket"));
    RightFistBox->SetCollisionProfileName(TEXT("NoCollision"));

    // 2. 왼손 박스
    LeftFistBox = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftFistBox"));
    LeftFistBox->SetupAttachment(GetMesh(), TEXT("LeftHandSocket"));
    LeftFistBox->SetCollisionProfileName(TEXT("NoCollision"));

    // 3. 몸통 돌진 박스 (기본 캡슐보다 조금 더 크게 설정 추천)
    BodyChargeBox = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BodyChargeBox"));
    BodyChargeBox->SetupAttachment(GetRootComponent()); // 루트에 붙임
    BodyChargeBox->SetCollisionProfileName(TEXT("NoCollision"));
}

// Called when the game starts or when spawned
void ABossCharacter::BeginPlay()
{
	Super::BeginPlay();
    // 이벤트 연결 (함수 하나를 여러 컴포넌트에 연결해도 됩니다!)
    RightFistBox->OnComponentBeginOverlap.AddDynamic(this, &ABossCharacter::OnAttackOverlap);
    LeftFistBox->OnComponentBeginOverlap.AddDynamic(this, &ABossCharacter::OnAttackOverlap);
    BodyChargeBox->OnComponentBeginOverlap.AddDynamic(this, &ABossCharacter::OnAttackOverlap);
	
}

// Called every frame
void ABossCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABossCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABossCharacter::SetAttackCollision(int32 PartIndex, bool bActive)
{
    FName NewProfile = bActive ? TEXT("OverlapAllDynamic") : TEXT("NoCollision");

    // PartIndex에 따라 켜는 부위를 다르게!
    switch (PartIndex)
    {
    case 0: // 돌진 모드 (전부 다 켬 or 몸통만 켬)
        BodyChargeBox->SetCollisionProfileName(NewProfile);
        RightFistBox->SetCollisionProfileName(NewProfile);
        LeftFistBox->SetCollisionProfileName(NewProfile);
        break;
    case 1: // 오른손 공격
        BodyChargeBox->SetCollisionProfileName(NewProfile);
        RightFistBox->SetCollisionProfileName(NewProfile);
        break;
    case 2: // 왼손 공격
        BodyChargeBox->SetCollisionProfileName(NewProfile);
        LeftFistBox->SetCollisionProfileName(NewProfile);
        break;
    }
}

void ABossCharacter::OnAttackOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // 나 자신이나, 이미 죽은 애는 무시
    if (OtherActor == this || !OtherActor) return;

    // 플레이어인지 확인 (Tag나 Class로 체크)
    if (OtherActor->ActorHasTag("Player"))
    {
        // 3. 데미지 적용! (여기서 10.0f는 데미지 양)
        //UGameplayStatics::ApplyDamage(OtherActor, 10.0f, GetController(), this, UDamageType::StaticClass());

        // (선택) 타격 이펙트/사운드 재생 코드 추가 가능
        UE_LOG(LogTemp, Warning, TEXT("Player Hit!"));
    }
}