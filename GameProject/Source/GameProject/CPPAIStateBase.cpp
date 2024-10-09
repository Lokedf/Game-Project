// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAIStateBase.h"
#include "AIController.h"
#include "MyAIController.h"
#include "CPPAIDecorator.h"

void UCPPAIStateBase::CompleteState(AAIController* Owner, bool bSuccess)
{
    AMyAIController* MyAIController = Cast<AMyAIController>(Owner);
    if (MyAIController && NextState)
    {
        if (CheckDecorators(Owner))
        {
            MyAIController->ChangeState(NextState);
        }
    }
}

bool UCPPAIStateBase::CheckDecorators(AAIController* Owner) const
{
    for (UCPPAIDecorator* Decorator : Decorators)
    {
        if (Decorator && !Decorator->CheckCondition(Owner))
        {
            return false;
        }
    }
    return true;
}