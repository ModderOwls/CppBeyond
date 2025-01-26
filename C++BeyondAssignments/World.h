#pragma once

#include <iostream>
#include <vector>
#include <time.h>

#include "Rules/StrategyRules.h"

class World {
private:
    const int gridSize = 25;
    bool grid[25][25];
    bool newGrid[25][25];

    StrategyRules* rules;

    int calculateNeighbors(int x, int y);
public:
    World();
    void update();
    void render();
    void setStrategyRules(StrategyRules* strategy);
    void randomizeGrid();
};