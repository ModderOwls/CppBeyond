
#include "StrategyVerticalityRules.h"

//Ended up looking like a Worms map generator, neat.
bool StrategyVerticalityRules::calculateState(int x, int y, bool currentState, int neighborsCount)
{
    //Check if its above 22 or under 3, at the vertical edges.
    if (y > 22 || y < 3)
    {
        //Rest works similarly to Standard or Comfy Life rules.
        if (currentState)
        {
            if (neighborsCount <= 1)
            {
                return false;
            }
            else if (neighborsCount == 3)
            {
                return false;
            }
        }
        else
        {
            if (neighborsCount > 2)
            {
                return true;
            }
        }
    }
    else
    {
        if (currentState) 
        {
            if (neighborsCount < 4)
            {
                return false;
            }
        }
        else
        {
            if (neighborsCount > 4)
            {
                return true;
            }
        }
    }

    return currentState;
}
