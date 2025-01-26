
#include "StrategyStandardRules.h"

bool StrategyStandardRules::calculateState(int x, int y, bool currentState, int neighborsCount)
{
    //If alive and there are less than 2 or more than 3 neighbors, die.
    if (currentState && (neighborsCount < 2 || neighborsCount > 3)) return false;
    //If dead and there are 3 neighbors, be alive.
    if (!currentState && neighborsCount == 3) return true;
    //Otherwise stay.
    return currentState;
}
