#pragma once

#include "StrategyRules.h"

class StrategyComfyLifeRules : public StrategyRules {
public:
    bool calculateState(int x, int y, bool currentState, int neighborsCount) override;
};