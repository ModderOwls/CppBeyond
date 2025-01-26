
#include "Boid.h"

#include "Rules/RuleSeperation.h"
#include "Rules/RuleAlignment.h"
#include "Rules/RuleCohesion.h"

Boid::Boid(float x, float y)
{
    this->position.x = x;
    this->position.y = y;

    this->velocity = sf::Vector2f(rand() % 3 - 1, rand() % 3 - 1);
}

void Boid::update(const std::vector<Boid>& boids, float width, float height) 
{
    //Add rules.
    RuleSeperation separationRule;
    RuleAlignment alignmentRule;
    RuleCohesion cohesionRule;

    //Calculate and add the velocity of said rules.
    auto alignment = alignmentRule.calculateRuleVelocity(*this, boids);
    auto cohesionForce = cohesionRule.calculateRuleVelocity(*this, boids);
    auto separationForce = separationRule.calculateRuleVelocity(*this, boids);

    velocity += alignment + cohesionForce + separationForce;

    //Limit boid speed to maxSpeed.
    float speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (speed > maxSpeed) {
        velocity /= speed;
        velocity *= maxSpeed;
    }

    //Add velocity.
    position += velocity;

    //Ensure they stay on screen by just teleporting them to the other side.
    if (position.x < 0) position.x += width;
    if (position.x > width) position.x -= width;
    if (position.y < 0) position.y += height;
    if (position.y > height) position.y -= height;
}

void Boid::render(sf::RenderWindow& window) 
{
    //Create boid circle.
    sf::CircleShape shape(5);
    shape.setPosition(position.x, position.y);
    shape.setFillColor(sf::Color::White);

    //Render the circle.
    window.draw(shape);
}

sf::Vector2f Boid::getPosition() const 
{
    return position;
}

sf::Vector2f Boid::getVelocity() const 
{
    return velocity;
}