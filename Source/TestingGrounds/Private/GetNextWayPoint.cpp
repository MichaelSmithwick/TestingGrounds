// Copyright (c) IdeaShadow Company - All Rights Reserved

#include "GetNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolPoints.h"


EBTNodeResult::Type UGetNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	// Get the PatrolPoints component attached to the object
	APawn* PawnGuard = OwnerComp.GetAIOwner()->GetPawn();
	UPatrolPoints* PatrolPoints = PawnGuard->FindComponentByClass<UPatrolPoints>();

	// verify the component exists
	if (PatrolPoints == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	// make sure there are some Patrol Points
	if (PatrolPoints->PatrolPointArraySize() <= 0)
	{
		return EBTNodeResult::Failed;
	}

	// Get the index of the next PatrolPoint
	int32 TheIndex = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);
	if (TheIndex < 0)
	{
		TheIndex = 0;
		Blackboard->SetValueAsInt(IndexKey.SelectedKeyName, TheIndex);
	}

	// Get the next PatrolPoint
	AActor* NextPatrolPoint = PatrolPoints->GetNextPatrolPoint(TheIndex);
	if (NextPatrolPoint == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	// If all the checks have been passed then calculate next PatrolPoint index
	// and save it along with the current PatrolPoint to the blackboard


	// Calculate the index for the next PatrolPoint
	TheIndex++;
	TheIndex %= PatrolPoints->PatrolPointArraySize();

	// set NextIndex and Current PatrolPoint
	Blackboard->SetValueAsInt(IndexKey.SelectedKeyName, TheIndex);
	Blackboard->SetValueAsObject(PatrolPoint.SelectedKeyName, NextPatrolPoint);

	return EBTNodeResult::Succeeded;
}


