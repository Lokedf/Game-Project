// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIStateBase.h"
#include "CPPClearFocusState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UCPPClearFocusState : public UCPPAIStateBase
{
	GENERATED_BODY()
public:
	virtual void EnterState(AAIController* Owner) override;
};
