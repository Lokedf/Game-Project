// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFocusState.h"
#include "MyAIController.h"

void UCPPFocusState::EnterState(AAIController* Owner)
{
	AMyAIController* MyAIController = Cast<AMyAIController>(Owner);
	if (MyAIController && MyAIController->myBlackboard)
	{
		Owner->SetFocus(MyAIController->myBlackboard->GetValue<AActor*>(KeyName));
	}
}
