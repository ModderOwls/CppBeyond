#pragma once

#include "BoidRule.h"

class RuleAlignment : public BoidRule
{
public:
	sf::Vector2f calculateRuleVelocity(const Boid& boid, const std::vector<Boid>& others) override;
};