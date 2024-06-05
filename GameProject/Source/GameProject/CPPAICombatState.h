// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIStateBase.h"
#include "CPPAICombatState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UCPPAICombatState : public UCPPAIStateBase
{
	GENERATED_BODY()

public:
    virtual void EnterState(AAIController* Owner) override;
    virtual void UpdateState(AAIController* Owner, float DeltaTime) override;
    virtual void ExitState(AAIController* Owner) override;

    // Handle perception updates
    void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);
	
};
