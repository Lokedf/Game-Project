// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineActor.h"
//#include "RotateLeftState.h"
//#include "RotateRightState.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AStateMachineActor::AStateMachineActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myStateMachine = std::make_unique<StateMachine>(this);
	//myStateMachine->AddState(std::make_shared<RotateLeftState>(), StateTypes::RotateLeft);
	//myStateMachine->AddState(std::make_shared<RotateRightState>(), StateTypes::RotateRight);
	//myStateMachine->EnterState(StateTypes::RotateRight);

	myStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = myStaticMesh;

	bReplicates = true;
}

// Called when the game starts or when spawned
void AStateMachineActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStateMachineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	myStateMachine->Update(DeltaTime);
}