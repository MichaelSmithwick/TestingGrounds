// Copyright (c) IdeaShadow Company - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Containers/Array.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:

	AActor* GetNextPatrolPoint(const int32 Index) const;

	int32 PatrolPointArraySize() const;

protected:
	UPROPERTY(EditInstanceOnly, Category="PatrolRoute")
	TArray<AActor*> PatrolPoints;
	
};
