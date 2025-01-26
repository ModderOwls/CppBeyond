
#include <iostream>

#include "World.h"

#include "Rules/StrategyStandardRules.h"
#include "Rules/StrategyComfyLifeRules.h"
#include "Rules/StrategyVerticalityRules.h"

#include <Windows.h>

int main()
{
    World world;

    //Change this to change the strategy.
    int strategy = 2;

    switch (strategy) 
    {
        case 0:
            world.setStrategyRules(new StrategyStandardRules);
            break;
        case 1:
            world.setStrategyRules(new StrategyComfyLifeRules);
            break;
        case 2:
            world.setStrategyRules(new StrategyVerticalityRules);
            break;
    }

    world.randomizeGrid();

    while (true) 
    {
        system("cls"); //Clear screen.

        world.render();
        world.update();

        //Note: only works on windows!! 
        //If you're not on windows just remove both it and #include <Windows.h>, this just makes it easier to see work.
        Sleep(100);
    }
}