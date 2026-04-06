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

void AMovingPlatform::Tick(float DeltaTime)
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

