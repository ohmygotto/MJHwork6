#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class MJHWORK6_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MobingPlatform|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MobingPlatform|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MobingPlatform|Components")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MobingPlatform|Components")
	float MaxRange;

	FVector StartLocation;

	float CurrentDistance = 0.f;

	int Direction = 1;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
