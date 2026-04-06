#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime) //엑터 회전 부분중 일부는 chatgpt를 이용해서 해결법 찾기 및 검수를 진행했습니다.
{
	Super::Tick(DeltaTime);

	float MoveStep = MoveSpeed * DeltaTime * Direction;

	AddActorLocalOffset(FVector(0.f, MoveStep, 0.f));

	CurrentDistance += FMath::Abs(MoveStep);

	if (CurrentDistance >= MaxRange)
	{
		Direction *= -1;
		CurrentDistance = 0.f;
	}

}

