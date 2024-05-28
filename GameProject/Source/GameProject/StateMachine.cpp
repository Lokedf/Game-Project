// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine.h"
#include "GameFramework/Actor.h"
#include "State.h"

StateMachine::StateMachine(AActor* anActor)
{
	myActor = anActor;
}

StateMachine::~StateMachine()
{
}

bool StateMachine::EnterState(const StateTypes aStateName)
{
	if (myStates.find(aStateName) != myStates.end())
	{
		if (myActiveState != nullptr)
		{
			myActiveState->OnExit();
		}
		myActiveState = myStates[aStateName];
		myActiveState->OnEnter();
		return true;
	}

	return false;
}

void StateMachine::AddState(std::shared_ptr<State> aState, const StateTypes aKey)
{
	aState->myStateMachine = this;
	myStates[aKey] = aState;
}

void StateMachine::Update(float aDeltaTime)
{
	myElapsedTime += aDeltaTime;
	myActiveState->Update(aDeltaTime);
}

float StateMachine::GetElapsedTime()
{
	return myElapsedTime;
}

void StateMachine::SetElapsedTime(float aNewTime)
{
	myElapsedTime = aNewTime;
}