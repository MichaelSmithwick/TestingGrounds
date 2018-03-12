// Copyright (c) IdeaShadow Company - All Rights Reserved

#include "PatrollingGuard.h"


AActor* APatrollingGuard::GetNextPatrolPoint(const int32 Index) const
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

int32 APatrollingGuard::PatrolPointArraySize() const
{
	return PatrolPoints.Num();
}
