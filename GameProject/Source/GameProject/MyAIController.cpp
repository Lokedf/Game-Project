// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
	// Initialize Perception Component and Sight Configuration
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	// Configure Sight
	SightConfig->SightRadius = 500.0f;
	SightConfig->LoseSightRadius = 550.0f;
	SightConfig->PeripheralVisionAngleDegrees = 90.0f;
	SightConfig->SetMaxAge(5.0f);
	SightConfig->AutoSuccessRangeFromLastSeenLocation = 900.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	// Add sight configuration to perception component
	AIPerceptionComponent->ConfigureSense(*SightConfig);
	AIPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());

	// Bind perception updated delegate
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AMyAIController::OnPerceptionUpdated);

	// Do not create the state machine here, do it in BeginPlay instead. Creating StateMachine causes engine breaking errors.
	StateMachine = nullptr;
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	// Initialize the state machine in BeginPlay
	StateMachine = NewObject<UCPPAIStateMachine>(this);
	StateMachine->Initialize(this);
	StateMachine->ChangeState(EAIState::Passive, this);
}

void AMyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	StateMachine->UpdateCurrentState(this, DeltaTime);
}

void AMyAIController::ChangeAIState(EAIState NewState)
{
	StateMachine->ChangeState(NewState, this);
}

void AMyAIController::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	// Handle perception updates
	for (AActor* Actor : UpdatedActors)
	{
		if (Actor->ActorHasTag("Player"))
		{
			// Example: Change to chase state if player is detected
			StateMachine->ChangeState(EAIState::Attack, this);
		}
	}
}

void AMyAIController::WieldWeaponEnemyBase()
{
	// Access the controlled pawn
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		// Cast to AEnemyBase
		AEnemyBase* EnemyBase = Cast<AEnemyBase>(ControlledPawn);
		if (EnemyBase)
		{
			// Access variables and call functions
			bool WieldingWeapon = EnemyBase->WieldingWeapon;
			EnemyBase->CPPWieldWeapon();
		}
	}
}
void AMyAIController::UnWieldWeaponEnemyBase()
{
	// Access the controlled pawn
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		// Cast to AEnemyBase
		AEnemyBase* EnemyBase = Cast<AEnemyBase>(ControlledPawn);
		if (EnemyBase)
		{
			// Access variables and call functions
			if(EnemyBase->WieldingWeapon)
				EnemyBase->CPPWieldWeapon();
		}
	}
}