// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTestComponent2ElectricBoogaloo.generated.h"

// Variables specific to this component.
struct int2
{
	int myX;
	int myY;
	int2() {};
	int2(int x, int y) : myX(x), myY(y) {};
};
USTRUCT()
struct FMyBitMask
{
	GENERATED_BODY()
	// I recommend using 1 as open and 2 as closed but the program is built to handle any setup really as long as it's consistent.
	UPROPERTY(EditAnywhere, Meta = (Bitmask))
	int myInt;
	FMyBitMask(int aValue) :myInt(aValue)
	{
	}
	FMyBitMask()
	{
	}
};
//TileType
USTRUCT(BlueprintType)
struct FMyTileType {
	GENERATED_BODY()
	// You can put your tile object here.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<AActor> myTileObject = nullptr;
	// Valid Neighbouring Connections. North, South, West, East
	UPROPERTY(EditAnywhere, Meta = (Bitmask))
	int myConnections[4];
	int myRotation = 0;

	// Constructor to initialize TileType objects
	FMyTileType()
	{}
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAMEPROJECT_API UMyTestComponent2ElectricBoogaloo : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyTestComponent2ElectricBoogaloo();
	// How many blocks in each dimension the tiles are.
	UPROPERTY(EditAnywhere)
	int TileScale = 16;
	// How many tiles the map is in each dimension.
	UPROPERTY(EditAnywhere)
	int GridSize = 5;
	// Defining a base for tiletypes
	UPROPERTY(EditAnywhere)
	TArray<FMyTileType> myTiles;

	TArray<AActor*> GeneratedTiles;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
};
