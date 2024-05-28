// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <unordered_map>

class AActor;
class State;

enum class StateTypes
{
	//RotateLeft,
	//RotateRight
};

class GAMEPROJECT_API StateMachine
{
public:
	StateMachine(AActor* anActor);
	~StateMachine();

	bool EnterState(const StateTypes aStateName);
	void AddState(std::shared_ptr<State> aState, const StateTypes aKey);
	void Update(float aDeltaTime);
	float GetElapsedTime();
	void SetElapsedTime(float aNewTime);

private:
	std::unordered_map<StateTypes, std::shared_ptr<State>> myStates;
	std::shared_ptr<State> myActiveState = nullptr;
	float myElapsedTime = 0.0f;

public:
	AActor* myActor; //Replace this with a struct(?) that holds everything one would need, will depend on what it'll be used for.
};
