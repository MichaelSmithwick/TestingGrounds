// Copyright (c) IdeaShadow Company - All Rights Reserved

#include "PatrolPoints.h"


// Sets default values for this component's properties
UPatrolPoints::UPatrolPoints()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPatrolPoints::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPatrolPoints::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor* UPatrolPoints::GetNextPatrolPoint(const int32 Index) const
{
	if (PatrolPoints.IsValidIndex(Index))
	{
		return PatrolPoints[Index];
	}
	else
	{
		return nullptr;
	}
}

int32 UPatrolPoints::PatrolPointArraySize() const
{
	return PatrolPoints.Num();
}
