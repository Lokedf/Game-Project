// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPPAIStates.h"
#include "CPPAIStateBase.generated.h" 

class UCPPAIDecorator;
class AAIController;
class AMyAIController;
UCLASS()
class GAMEPROJECT_API UCPPAIStateBase : public UObject
{

	GENERATED_BODY()

public:
	//virtual ~UCPPAIStateBase() = default;
	EAIState StateEnum = EAIState::Passive;
	virtual void EndAction() {}
	virtual void EnterState(AAIController* Owner) {}
	virtual void UpdateState(AAIController* Owner, float DeltaTime) {}
	virtual void ExitState(AAIController* Owner) {}

	// Reference to the next state
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AIState")
	UCPPAIStateBase* NextState;

	// Function to call when the state is complete
	virtual void CompleteState(class AAIController* Owner, bool bSuccess);

	// Decorators to check before transitioning
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AIState")
	TArray<UCPPAIDecorator*> Decorators;

protected:
	bool CheckDecorators(AAIController* Owner) const;
};