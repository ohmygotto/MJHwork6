#include "RotationPlatform.h"

ARotationPlatform::ARotationPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


}

void ARotationPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotationPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, MoveSpeed * DeltaTime, 0.0f));
	}
}

