// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NetworkCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class GAMEPROJECT_API ANetworkCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* myCameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* myFollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* myFollowCameraPOV;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputMappingContext* myDefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* myJumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* myMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* myLookAction;

public:
	ANetworkCharacter();

protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return myCameraBoom; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return myFollowCamera; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE class UCameraComponent* GetFollowCameraPOV() const { return myFollowCameraPOV; }

#pragma region NetworkClockSync

protected:

	/** Frequency that the client requests to adjust it's local clock. Set to zero to disable periodic updates. */
	UPROPERTY(EditDefaultsOnly, Category = GameState)
		float NetworkClockUpdateFrequency = 1.f;

private:

	float ServerWorldTimeDelta = 0.f;
	TArray<float> RTTCircularBuffer;

public:

	UFUNCTION(BlueprintPure)
		float GetServerWorldTimeDelta() const;

	UFUNCTION(BlueprintPure)
		float GetServerWorldTime() const;

	void PostNetInit() override;

private:

	void RequestWorldTime_Internal();

	UFUNCTION(Server, Unreliable)
		void ServerRequestWorldTime(float ClientTimestamp);

	UFUNCTION(Client, Unreliable)
		void ClientUpdateWorldTime(float ClientTimestamp, float ServerTimestamp);

#pragma endregion NetworkClockSync
};
