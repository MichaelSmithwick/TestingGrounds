// Copyright (c) IdeaShadow Company - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolPoints.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolPoints : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolPoints();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "PatrolRoute")
	AActor * GetNextPatrolPoint(const int32 Index) const;

	UFUNCTION(BlueprintCallable, Category = "PatrolRoute")
	int32 PatrolPointArraySize() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, Category = "PatrolRoute")
	TArray<AActor*> PatrolPoints;


};
