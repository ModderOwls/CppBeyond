#pragma once

class StrategyRules
{
public:
	virtual bool calculateState(int x, int y, bool currentState, int neighborsCount);
};