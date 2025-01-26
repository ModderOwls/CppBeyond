
#include "RuleAlignment.h"

sf::Vector2f RuleAlignment::calculateRuleVelocity(const Boid& boid, const std::vector<Boid>& others)
{
    sf::Vector2f steer(0, 0);
    int count = 0;

    //Check for nearby neighbors and add them to the total velocity.
    for (int i = 0; i < others.size(); ++i) 
    {
        float x = others[i].getPosition().x - boid.getPosition().x;
        float y = others[i].getPosition().y - boid.getPosition().y;

        float distance = std::sqrt(x * x + y * y);

        if (distance > 0 && distance < boid.radiusNeighbors) 
        {
            steer += others[i].getVelocity();
            ++count;
        }
    }

    //If any neighbors are found, calculate the average heading of the velocities.
    if (count > 0) 
    {
        steer /= (float)count;

        //Steer towards heading.
        float mag = std::sqrt(steer.x * steer.x + steer.y * steer.y);
        if (mag > 0) 
        {
            steer /= mag;
            steer *= boid.maxSpeed;
            steer -= boid.getVelocity();

            //Ensure new force isn't above maxForce.
            mag = std::sqrt(steer.x * steer.x + steer.y * steer.y);
            if (mag > boid.maxForce) {
                steer /= mag;
                steer *= boid.maxForce;
            }
        }
    }

    return steer;
}