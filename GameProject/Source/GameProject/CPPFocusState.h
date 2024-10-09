// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIStateBase.h"
#include "CPPFocusState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UCPPFocusState : public UCPPAIStateBase
{
	GENERATED_BODY()
public:
	virtual void EnterState(AAIController* Owner) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	FName KeyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	UObject* ExpectedValue;
};
