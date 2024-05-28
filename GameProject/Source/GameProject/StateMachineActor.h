// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StateMachine.h"
#include "StateMachineActor.generated.h"

UCLASS()
class GAMEPROJECT_API AStateMachineActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStateMachineActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Mesh to Render
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* myStaticMesh;

	std::unique_ptr<StateMachine> myStateMachine;
};
