#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <algorithm>

class Boid
{
public:
    Boid(float x, float y);

    void update(const std::vector<Boid>& boids, float width, float height);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    sf::Vector2f getVelocity() const;

    const float maxSpeed = 5.0f;
    const float maxForce = 0.3f;
    const float radiusNeighbors = 50.0f;

private:
    sf::Vector2f position;
    sf::Vector2f velocity;
};