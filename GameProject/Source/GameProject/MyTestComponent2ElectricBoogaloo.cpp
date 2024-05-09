// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestComponent2ElectricBoogaloo.h"
#include <random>
#include <vector>
#include <array>

using namespace std;

// Define the size of the grid
int GRID_SIZE = 5;

// Define the number of possible states for each cell
const int NUM_STATES = 5;


const int Directions = 4; // Making this a constant for now, might change later.



// Function to initialize the grid with random data
int RandomizeValue(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> disValue(min, max - 1);
	return disValue(gen);
	//for (auto& row : grid) {
	//	for (auto& tile : row) {
	//		tile.value = disValue(gen); // Randomly initialize tile value
	//		for (int& connection : tile.connections) {
	//			connection = disConnection(gen); // Randomly initialize connections
	//		}
	//	}
	//}
}

// Define a structure to represent a tile
struct Tile {
	std::vector<FMyTileType> myEntropy; // Tile value
	int myConnections[4]; // Connections with neighboring tiles

	int myPosition[2];
	//void SetConnections()
	//{
	//	for (FMyTileType tempEntropy : myEntropy) // Do not let Entropy types go too high, I'd much rather multiple fast WFC runs than one super slow one.
	//	{
	//		for (int i = 0; i < 4; ++i) { // Potentially problematic performance-wise, should however never go beyond 26 (3D + corners) so it might be safe.

	//			myConnections[i] |= tempEntropy.myConnections[i];
	//		}
	//	}
	//};
	void UpdateConnections()
	{
		for (int i = 0; i < Directions; i++) //Clearing directions
		{
			myConnections[i] = 0;
		}
		for (FMyTileType i : myEntropy) //Readding new directions based off of available tiles.
		{
			for (int o = 0; o < Directions; o++)
			{
				myConnections[o] |= i.myConnections[o];
			}
		}
	}
	bool CompareNeighborFlags(int flags, int dir)
	{
		if (flags != myConnections[dir])
		{
			if (myEntropy.size() > 1)
				myConnections[dir] = flags;

			for (int i = 0; i < myEntropy.size(); i++)
			{
				if ((flags & myEntropy[i].myConnections[dir]) != 0)
				{
					continue;
				}
				myEntropy.erase(myEntropy.begin() + i);
				i--;
			}
			UpdateConnections();
			return true;
		}
		return false;
	}
	int GetConnection(int dir)
	{
		if (dir >= Directions)
		{
			return myConnections[Directions - 1];
		}
		return myConnections[dir];
	}
	void Collapse()
	{
		FMyTileType tileType = myEntropy[RandomizeValue(0, myEntropy.size())];
		myEntropy.clear();
		myEntropy.push_back(tileType);
	}
	int GetEntropy()
	{
		return myEntropy.size();
	}

	// Constructor to initialize tile
	Tile(const int& row, const int& column, const std::vector<FMyTileType>& tileType) {
		myEntropy = tileType;
		myPosition[0] = row;
		myPosition[1] = column;
		UpdateConnections();
	}
	Tile()
	{}
};

// Define a 2D grid type
using Grid = vector<vector<Tile>>;

// Function to print the grid
//void UMyTestComponent2ElectricBoogaloo::PrintGrid(const Grid& grid) {
//	FTransform SpawnTransform;
//	for (int row = 0; row < grid.size(); row++) {
//		for (int tile = 0; tile < grid[row].size(); tile++) {
//			if (grid[row][tile].myEntropy.size() == 0 || grid[row][tile].myEntropy[0].myTileObject == nullptr)
//			{
//				//UE_LOG(LogTemp, Warning, TEXT("Something generated with zero entropy or a tile to generate was empty!"));
//				continue;
//			}
//			SpawnTransform.SetLocation(FVector(row * TileScale, 0, tile * TileScale));
//			SpawnTransform.SetRotation(FQuat::Identity); // No rotation
//			GeneratedTiles.Add(GetWorld()->SpawnActor<AActor>(grid[row][tile].myEntropy[0].myTileObject->GetClass(), SpawnTransform));
//		}
//	}
//};



// Define offsets for neighboring tiles (assuming a 2D grid)
const int neighborOffsets[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // North, South, West, East

// Function to get neighboring tiles of a given tile // North, South, West, East
int2 getNeighbor(const Grid& grid, int row, int col, int dir) {
	int newRow = row + neighborOffsets[dir][0];
	int newCol = col + neighborOffsets[dir][1];


	// Add the address of the neighboring tile to the list
	// Check if the new coordinates are within the bounds of the grid
	if (newRow >= 0 && newRow < grid.size() &&
		newCol >= 0 && newCol < grid[0].size()) {
		return { newRow, newCol };
	}
	return { -1, -1 };

}

// might use later.
// Check if the new coordinates are within the bounds of the grid
//if (newRow >= 0 && newRow < grid.size() &&
//	newCol >= 0 && newCol < grid[0].size()) {

// Delete collapsed, find lowest entropy, move lowest entropy to top of list and send back the top of the list, this should allow us to save a little time next time this is called.
int2 PickNextTileToCollapse(Grid& aGrid, std::vector<int2>& availablePositions)
{
	// temporary stand-in
	int2 currTile = { -1, -1 }; //Presetting it to something theoretically impossible.
	while (availablePositions.size() > 0 && (currTile.myX != availablePositions.back().myX || currTile.myY != availablePositions.back().myY))
	{
		if (aGrid[availablePositions.back().myX][availablePositions.back().myY].GetEntropy() < 2)
		{
			availablePositions.pop_back();
			continue;
		}
		currTile = availablePositions.back();

	}
	if (availablePositions.size() < 1) //Early exit in case all the tiles have collapsed.
		return { -1,-1 };

	availablePositions.pop_back();
	Tile* tempTile = nullptr;
	for (int i = availablePositions.size() - 1; i > -1; i--)
	{
		tempTile = &aGrid[availablePositions[i].myX][availablePositions[i].myY];
		if (tempTile->GetEntropy() < 2)
		{
			availablePositions.erase(availablePositions.begin() + i);
			continue;
		}
		if (aGrid[currTile.myX][currTile.myY].GetEntropy() > tempTile->GetEntropy())
		{
			availablePositions.push_back(currTile);
			currTile = availablePositions[i];
		}
	}
	Tile& tile = aGrid[currTile.myX][currTile.myY];
	tile.Collapse();
	tile.UpdateConnections();
	return currTile;


};

void WaveFunctionCollapse(Grid& aGrid, std::vector<int2> theTiles)
{
	int2 nextTile = { GRID_SIZE / 2,GRID_SIZE / 2 };
	std::vector<int2> myCalculateEntropyList;
	std::vector<int2> myNoncollapsedTiles = theTiles;
	{ // collapsing a central tile
		Tile* tile = &aGrid[nextTile.myX][nextTile.myY];
		FMyTileType tileType = tile->myEntropy[RandomizeValue(0, tile->myEntropy.size())];
		tile->myEntropy.clear();
		tile->myEntropy.push_back(tileType);
		std::vector<int2> tempCollapseCheck;
		for (int i = 0; i < Directions; i++)
			tempCollapseCheck.push_back(getNeighbor(aGrid, nextTile.myX, nextTile.myY, i));
		for (int2 i : tempCollapseCheck) // Something to start up the impending collapse.
		{
			if (i.myX < 0)
				continue;
			Tile tempTile = aGrid[i.myX][i.myY];
			if (tempTile.GetEntropy() == 1)
				continue;
			myCalculateEntropyList.push_back(i);
		}
	}
	while (!myNoncollapsedTiles.empty()) //Looks spooky but this is like the core of the whole function.
	{
		Tile* theTile;
		while (!myCalculateEntropyList.empty()) //Now this is spooky but I think it might be needed.
		{
			Tile* neighbor;
			int2 neighborPosition;
			nextTile = myCalculateEntropyList.back();
			myCalculateEntropyList.pop_back();
			theTile = &aGrid[nextTile.myX][nextTile.myY];
			for (int i = 0; i < Directions; i++)
			{
				neighborPosition = getNeighbor(aGrid, nextTile.myX, nextTile.myY, i);
				if (neighborPosition.myX < 0) //Checking that it's not a bad location.
					continue;
				neighbor = &aGrid[neighborPosition.myX][neighborPosition.myY];
				if (theTile->CompareNeighborFlags(neighbor->GetConnection(i + (((i % 2) * -2) + 1)), i)) // Moved the inversion calculation to here.
				{
					myCalculateEntropyList.push_back(neighborPosition);
				}
			}
		}
		myCalculateEntropyList.push_back(PickNextTileToCollapse(aGrid, myNoncollapsedTiles));
	}


	// Placing tiles in the first list.

};
// Main function to demonstrate the WFC algorithm
//int main() {
//	// Create and initialize the grid
//	std::vector<int2> TotalTiles;
//	Grid grid(GRID_SIZE, vector<Tile>(GRID_SIZE));
//	for (int row = 0; row < GRID_SIZE; ++row) {
//		for (int col = 0; col < GRID_SIZE; ++col) {
//			grid[row][col] = Tile(row, col); // Initialize tile with row and column indices
//			TotalTiles.push_back({ row,col }); // I thought it would be best to make this list here.
//		}
//	}
//
//	// This is where the wave function collapse is called, it takes in the grid and a list of all tiles in the grid.
//	WaveFunctionCollapse(grid, TotalTiles);
//	// Print the final grid after applying WFC
//	PrintGrid(grid);
//
//	return 0;
//}
// Sets default values for this component's properties
UMyTestComponent2ElectricBoogaloo::UMyTestComponent2ElectricBoogaloo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
};


// Called when the game starts
void UMyTestComponent2ElectricBoogaloo::BeginPlay()
{
	//Super::BeginPlay();
	GRID_SIZE = GridSize;


	Grid grid(GridSize, vector<Tile>(GridSize));
	do
	{
		// Create and initialize the grid
		std::vector<FMyTileType> myTotalTiletypes;
		{
			FMyTileType tempTileType;
			bool isDifferent = false;
			for (int i = 0; i < myTiles.Num(); i++)
			{
				std::vector<std::array<int, 4>> tempConnections;
				tempConnections.push_back({ 0,0,0,0 });
				for (int l = 0; l < 4; l++)
				{
					tempConnections.back()[l] = myTiles[i].myConnections[l];
				}

				tempTileType = myTiles[i];
				for (int o = 1; o < 4; o++)// Rotations starting from 90;
				{
					tempConnections.push_back({ 0,0,0,0 });
					for (int u = 0; u < 4; u++) { //connections
						tempConnections.back()[u] = myTiles[i].myConnections[(u + o + 4) % 4];
					}
					for (int j = 0; j < tempConnections.size() - 1 && isDifferent == false; j++)
					{
						for (int l = 0; l < 4; l++)
						{
							if (tempConnections[j][l] != tempConnections[tempConnections.size()][l])
							{
								isDifferent = true;
								break;
							}
						}

					}
					if (isDifferent == false)
					{
						tempConnections.pop_back();
						continue;
					}
					tempTileType.myRotation = o;
					for (int l = 0; l < 4; l++)
					{
						tempTileType.myConnections[l] = tempConnections.back()[l];
					}
					isDifferent = false;
					myTotalTiletypes.push_back(tempTileType);
					myTotalTiletypes.back().myRotation = o; // The rotation, each int is 90 degrees
					// Adjust connections based on the rotation difference

				}
			}
		}
		std::vector<int2> TotalTiles;

		for (int row = 0; row < GridSize; ++row) {
			for (int col = 0; col < GridSize; ++col) {
				grid[row][col] = Tile(row, col, myTotalTiletypes); // Initialize tile with row and column indices
				grid[row][col].UpdateConnections();
				TotalTiles.push_back({ row,col }); // I thought it would be best to make this list here.
			}
		}

		// This is where the wave function collapse is called, it takes in the grid and a list of all tiles in the grid.

		WaveFunctionCollapse(grid, TotalTiles);
	} while (grid[0][0].GetEntropy() == 0);
	// Print the final grid after applying WFC

	FTransform SpawnTransform;
	for (int row = 0; row < grid.size(); row++) {
		for (int tile = 0; tile < grid[row].size(); tile++) {
			if (grid[row][tile].myEntropy.size() == 0 || grid[row][tile].myEntropy[0].myTileObject == nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Skipping tile: zero entropy or TileBlueprintClass is nullptr."))
					continue;
			}
			SpawnTransform.SetLocation(FVector(row * TileScale * 100, tile * TileScale * 100, 0));

			// Set rotation
			// Assuming rotation is in degrees, and you are rotating around the Z-axis
			float rotationDegrees = grid[row][tile].myEntropy[0].myRotation * 90.0f;
			SpawnTransform.SetRotation(FQuat(FRotator(0, rotationDegrees, 0))); // Set rotation around Y (Z) axis
			AActor* spawnedActor = GetWorld()->SpawnActor<AActor>(grid[row][tile].myEntropy[0].myTileObject, SpawnTransform);
			if (spawnedActor != nullptr) {
				GeneratedTiles.Add(spawnedActor);
			}
			else {
				UE_LOG(LogTemp, Error, TEXT("Failed to spawn actor at row: %d, tile: %d"), row, tile);
			}
		}
	}
	//PrintGrid(grid);

};


// Called every frame
void UMyTestComponent2ElectricBoogaloo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
};

