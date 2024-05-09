#include "MyActorTest2.h"
//#include <iostream>
//#include <vector>
//#include <random>
//
//using namespace std;
//
//// Define the size of the grid
//const int GRID_SIZE = 5;
//
//// Define the number of possible states for each cell
//const int NUM_STATES = 5;
//
//const std::string TYPE[5] = { "J", "L", "T", "I", "+" };
//
//const int Directions = 4; // Making this a constant for now, might change later.
//
//struct int2
//{
//	int myX;
//	int myY;
//	int2() {};
//	int2(int x, int y) : myX(x), myY(y) {};
//};
//// defining directions so I don't go insane trying to debug later. to invert just use this formula x + (((x % 2) * -2) + 1)
//#define NORTH 0;
//#define SOUTH 1;
//#define WEST 2;
//#define EAST 3;
//
//
//// Connection Flags, will replace with bitmaps after moving on to user testing.
//enum ConnectionFlags {
//	None = 0,
//	Open = 1 << 0,
//	Closed = 1 << 1
//};

//
//// Function to initialize the grid with random data
//int RandomizeValue(int min, int max) {
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<int> disValue(min, max - 1);
//	return disValue(gen);
//	//for (auto& row : grid) {
//	//	for (auto& tile : row) {
//	//		tile.value = disValue(gen); // Randomly initialize tile value
//	//		for (int& connection : tile.connections) {
//	//			connection = disConnection(gen); // Randomly initialize connections
//	//		}
//	//	}
//	//}
//}
//
//TileType XField(4, (ConnectionFlags)1, (ConnectionFlags)1, (ConnectionFlags)1, (ConnectionFlags)1);
//TileType ICorridor(3, (ConnectionFlags)1, (ConnectionFlags)1, (ConnectionFlags)2, (ConnectionFlags)2);
//TileType TJunction(2, (ConnectionFlags)2, (ConnectionFlags)1, (ConnectionFlags)1, (ConnectionFlags)1);
//TileType LCorner(1, (ConnectionFlags)1, (ConnectionFlags)2, (ConnectionFlags)2, (ConnectionFlags)1);
//TileType JCorner(0, (ConnectionFlags)1, (ConnectionFlags)2, (ConnectionFlags)1, (ConnectionFlags)2);
//
//// Define a structure to represent a tile
//struct Tile {
//	std::vector<TileType> myEntropy = { JCorner,LCorner,TJunction,ICorridor,XField }; // Tile value
//	ConnectionFlags myConnections[4]; // Connections with neighboring tiles
//
//	int myPosition[2];
//	void SetConnections()
//	{
//		for (TileType tempEntropy : myEntropy) // Do not let Entropy types go too high, I'd much rather multiple fast WFC runs than one super slow one.
//		{
//			for (int i = 0; i < 4; ++i) { // Potentially problematic performance-wise, should however never go beyond 26 (3D + corners) so it might be safe.
//
//				myConnections[i] = static_cast<ConnectionFlags>(myConnections[i] | tempEntropy.myConnections[i]); // Static casting because even though it's all enums VS thinks it's int.
//			}
//		}
//	};
//	void UpdateConnections()
//	{
//		for (int i = 0; i < Directions; i++) //Clearing directions
//		{
//			myConnections[i] = None;
//		}
//		for (TileType i : myEntropy) //Readding new directions based off of available tiles.
//		{
//			for (int o = 0; o < Directions; o++)
//			{
//				myConnections[o] = static_cast<ConnectionFlags>(myConnections[o] | i.myConnections[o]);
//			}
//		}
//	}
//	bool CompareNeighborFlags(ConnectionFlags flags, int dir)
//	{
//		if (flags != myConnections[dir])
//		{
//			if (myEntropy.size() > 1)
//				myConnections[dir] = flags;
//
//			for (int i = 0; i < myEntropy.size(); i++)
//			{
//				if ((flags & myEntropy[i].myConnections[dir]) != 0)
//				{
//					continue;
//				}
//				myEntropy.erase(myEntropy.begin() + i);
//				i--;
//			}
//			UpdateConnections();
//			return true;
//		}
//		return false;
//	}
//	ConnectionFlags GetConnection(int dir)
//	{
//		if (dir >= Directions)
//		{
//			return myConnections[Directions - 1];
//		}
//		return myConnections[dir];
//	}
//	void Collapse()
//	{
//		TileType tileType = myEntropy[RandomizeValue(0, myEntropy.size())];
//		myEntropy.clear();
//		myEntropy.push_back(tileType);
//	}
//	int GetEntropy()
//	{
//		return myEntropy.size();
//	}
//
//	// Constructor to initialize tile
//	Tile(int row, int column) {
//		myPosition[0] = row;
//		myPosition[1] = column;
//		SetConnections();
//	}
//	Tile()
//	{}
//};
//
//// Define a 2D grid type
//using Grid = vector<vector<Tile>>;
//
//// Function to print the grid
//void printGrid(const Grid& grid) {
//	for (const auto& row : grid) {
//		for (const auto& tile : row) {
//			if (tile.myEntropy.size() == 0)
//			{
//				cout << "*" << " | ";
//				continue;
//			}
//
//			cout << TYPE[tile.myEntropy[0].myValue] << " | "; // Using the last remaining entropy variable.
//		}
//		cout << endl;
//	}
//}
//
//
//
//// Define offsets for neighboring tiles (assuming a 2D grid)
//const int neighborOffsets[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // North, South, West, East
//
//// Function to get neighboring tiles of a given tile // North, South, West, East
//int2 getNeighbor(const Grid& grid, int row, int col, int dir) {
//	int newRow = row + neighborOffsets[dir][0];
//	int newCol = col + neighborOffsets[dir][1];
//
//
//	// Add the address of the neighboring tile to the list
//	// Check if the new coordinates are within the bounds of the grid
//	if (newRow >= 0 && newRow < grid.size() &&
//		newCol >= 0 && newCol < grid[0].size()) {
//		return { newRow, newCol };
//	}
//	return { -1, -1 };
//
//}
//
//// might use later.
//// Check if the new coordinates are within the bounds of the grid
////if (newRow >= 0 && newRow < grid.size() &&
////	newCol >= 0 && newCol < grid[0].size()) {
//
//// Delete collapsed, find lowest entropy, move lowest entropy to top of list and send back the top of the list, this should allow us to save a little time next time this is called.
//int2 PickNextTileToCollapse(Grid& aGrid, std::vector<int2>& availablePositions)
//{
//	// temporary stand-in
//	int2 currTile = { -1, -1 }; //Presetting it to something theoretically impossible.
//	while (availablePositions.size() > 0 && (currTile.myX != availablePositions.back().myX || currTile.myY != availablePositions.back().myY))
//	{
//		if (aGrid[availablePositions.back().myX][availablePositions.back().myY].GetEntropy() < 2)
//		{
//			availablePositions.pop_back();
//			continue;
//		}
//		currTile = availablePositions.back();
//
//	}
//	if (availablePositions.size() < 1) //Early exit in case all the tiles have collapsed.
//		return { -1,-1 };
//
//	availablePositions.pop_back();
//	Tile* tempTile = nullptr;
//	for (int i = availablePositions.size() - 1; i > -1; i--)
//	{
//		tempTile = &aGrid[availablePositions[i].myX][availablePositions[i].myY];
//		if (tempTile->GetEntropy() < 2)
//		{
//			availablePositions.erase(availablePositions.begin() + i);
//			continue;
//		}
//		if (aGrid[currTile.myX][currTile.myY].GetEntropy() > tempTile->GetEntropy())
//		{
//			availablePositions.push_back(currTile);
//			currTile = availablePositions[i];
//		}
//	}
//	Tile& tile = aGrid[currTile.myX][currTile.myY];
//	tile.Collapse();
//	tile.UpdateConnections();
//	return currTile;
//
//
//};
//
//void WaveFunctionCollapse(Grid& aGrid, std::vector<int2> theTiles)
//{
//	int2 nextTile = { GRID_SIZE / 2,GRID_SIZE / 2 };
//	std::vector<int2> myCalculateEntropyList;
//	std::vector<int2> myNoncollapsedTiles = theTiles;
//	{ // collapsing a central tile
//		Tile* tile = &aGrid[nextTile.myX][nextTile.myY];
//		TileType tileType = tile->myEntropy[RandomizeValue(0, NUM_STATES)];
//		tile->myEntropy.clear();
//		tile->myEntropy.push_back(tileType);
//		std::vector<int2> tempCollapseCheck;
//		for (int i = 0; i < Directions; i++)
//			tempCollapseCheck.push_back(getNeighbor(aGrid, nextTile.myX, nextTile.myY, i));
//		for (int2 i : tempCollapseCheck) // Something to start up the impending collapse.
//		{
//			if (i.myX < 0)
//				continue;
//			Tile tempTile = aGrid[i.myX][i.myY];
//			if (tempTile.GetEntropy() == 1)
//				continue;
//			myCalculateEntropyList.push_back(i);
//		}
//	}
//	while (!myNoncollapsedTiles.empty()) //Looks spooky but this is like the core of the whole function.
//	{
//		Tile* theTile;
//		while (!myCalculateEntropyList.empty()) //Now this is spooky but I think it might be needed.
//		{
//			Tile* neighbor;
//			int2 neighborPosition;
//			nextTile = myCalculateEntropyList.back();
//			myCalculateEntropyList.pop_back();
//			theTile = &aGrid[nextTile.myX][nextTile.myY];
//			for (int i = 0; i < Directions; i++)
//			{
//				neighborPosition = getNeighbor(aGrid, nextTile.myX, nextTile.myY, i);
//				if (neighborPosition.myX < 0) //Checking that it's not a bad location.
//					continue;
//				neighbor = &aGrid[neighborPosition.myX][neighborPosition.myY];
//				if (theTile->CompareNeighborFlags(neighbor->GetConnection(i + (((i % 2) * -2) + 1)), i)) // Moved the inversion calculation to here.
//				{
//					myCalculateEntropyList.push_back(neighborPosition);
//				}
//			}
//		}
//		myCalculateEntropyList.push_back(PickNextTileToCollapse(aGrid, myNoncollapsedTiles));
//	}
//
//
//	// Placing tiles in the first list.
//
//};
//// Main function to demonstrate the WFC algorithm
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
//	// Filling the grid with random data could cause errors, might reuse code for different, less problematic input system.
//	//initializeGrid(grid);
//
//	// Print the initial grid
//	cout << "Initial grid:" << endl;
//	printGrid(grid);
//	cout << endl;
//
//	// This is where the wave function collapse is called, it takes in the grid and a list of all tiles in the grid.
//	WaveFunctionCollapse(grid, TotalTiles);
//	// Print the final grid after applying WFC
//	cout << "Final grid:" << endl;
//	printGrid(grid);
//
//	return 0;
//}

AMyActorTest2::AMyActorTest2()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActorTest2::BeginPlay()
{
	Super::BeginPlay();
}

void AMyActorTest2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
