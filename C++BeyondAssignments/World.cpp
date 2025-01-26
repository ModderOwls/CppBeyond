
#include "World.h"

World::World() { }

void World::setStrategyRules(StrategyRules* strategy)
{
	rules = strategy;
}

void World::randomizeGrid() 
{
    //Ensure its random each time.
    std::srand(std::time(NULL));

    for (int i = 0; i < gridSize; ++i)
        for (int j = 0; j < gridSize; ++j)
            grid[i][j] = std::rand() % 2;
}

int World::calculateNeighbors(int x, int y) 
{
    int neighbors = 0;

    //Gets all surrounding neighbours in a 3x3 grid.
    for (int dy = -1; dy <= 1; ++dy) 
    {
        for (int dx = -1; dx <= 1; ++dx) 
        {
            //Ensure it wont count itself.
            if (dx == 0 && dy == 0) continue;

            //Calculate grid position.
            int nx = x + dx, ny = y + dy;

            //Ensure it isn't outside the grid vertically.
            if (ny < 0 || ny >= gridSize) continue;

            //Ensure it isn't outside the grid horizontally.
            if (nx < 0 || nx >= gridSize) continue;

            //Lastly check if it's alive.
            if (!grid[nx][ny]) continue;

            neighbors++;
        }
    }

    return neighbors;
}

void World::update() 
{
    //Calculate the neighbors of each cell and update the cell.
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            int neighbors = calculateNeighbors(x, y);
            newGrid[x][y] = rules->calculateState(x, y, grid[x][y], neighbors);
        }
    }

    //Update old grid to new one.
    for (int y = 0; y < gridSize; ++y)
    {
        for (int x = 0; x < gridSize; ++x)
        {
            grid[y][x] = newGrid[y][x];
        }
    }
}

void World::render() 
{
    //Render each line and row.
    //Using three characters per cell as its a bit easier to see.
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            std::cout << (grid[x][y] ? "[*]" : "   ");
        }

        std::cout << std::endl;
    }
}