
#include "StrategyComfyLifeRules.h"

//More generous to life, creates continuous movement instead of stopping at some point.
bool StrategyComfyLifeRules::calculateState(int x, int y, bool currentState, int neighborsCount)
{
    //If alive and there are less than 2 or more than 4 neighbors, die.
    if (currentState && (neighborsCount < 2 || neighborsCount > 4)) return false;
    //If dead and there are 3 or 4 neighbors, be alive.
    if (!currentState && (neighborsCount == 3 || neighborsCount == 4)) return true;
    //Otherwise stay.
    return currentState;
}
