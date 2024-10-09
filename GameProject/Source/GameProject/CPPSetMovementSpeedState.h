// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIStateBase.h"
#include "CPPSetMovementSpeedState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UCPPSetMovementSpeedState : public UCPPAIStateBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float MovementSpeed;

    virtual void EnterState(AAIController* Owner) override;
	
};
