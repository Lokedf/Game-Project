// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class StateMachine;

class GAMEPROJECT_API State
{
	friend class StateMachine;

public:
	State() = default;
	~State() = default;

protected:
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
	virtual void Update(float aDeltaTime) = 0;

protected:
	StateMachine* myStateMachine = nullptr;
};
