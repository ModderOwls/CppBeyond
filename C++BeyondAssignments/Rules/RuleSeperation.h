#pragma once

#include "BoidRule.h"

class RuleSeperation : public BoidRule
{
public:
	sf::Vector2f calculateRuleVelocity(const Boid& boid, const std::vector<Boid>& others) override;
};