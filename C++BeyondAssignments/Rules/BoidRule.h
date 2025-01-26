#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Boid.h"

class BoidRule
{
public:
	virtual ~BoidRule() = default;
	virtual sf::Vector2f calculateRuleVelocity(const Boid& boid, const std::vector<Boid>& others);
};