#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationPlatform.generated.h"

UCLASS()
class MJHWORK6_API ARotationPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotationPlatform();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationPlatform|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationPlatform|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationPlatform|Properties")
	float MoveSpeed;


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
