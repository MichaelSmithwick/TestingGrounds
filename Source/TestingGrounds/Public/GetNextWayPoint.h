// Copyright (c) IdeaShadow Company - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "GetNextWayPoint.generated.h"

//struct FBlackboardKeySelector;

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UGetNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	/** starts this task, should return Succeeded, Failed or InProgress
	*  (use FinishLatentTask() when returning InProgress)
	* this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector PatrolPoint;

};
