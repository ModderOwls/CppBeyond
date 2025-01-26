
#include "RuleCohesion.h"

#include <iostream>

sf::Vector2f RuleCohesion::calculateRuleVelocity(const Boid& boid, const std::vector<Boid>& others)
{
    sf::Vector2f center(0, 0);
    int count = 0;

    //Check for nearby neighbors and add them to the center.
    for (int i = 0; i < others.size(); ++i) 
    {
        float x = others[i].getPosition().x - boid.getPosition().x;
        float y = others[i].getPosition().y - boid.getPosition().y;

        float distance = std::sqrt(x*x + y*y);

        if (distance > 0 && distance < boid.radiusNeighbors)
        {
            center += others[i].getPosition();
            ++count;
        }
    }

    //If any neighbors are found, calculate the center excluding itself.
    if (count > 0) 
    {
        center /= (float)count;
        center -= boid.getPosition();

        //Steer towards center.
        float mag = std::sqrt(center.x * center.x + center.y * center.y);
        if (mag > 0) 
        {
            center /= mag;
            center *= boid.maxSpeed;
            center -= boid.getVelocity();

            //Ensure new force isn't above maxForce.
            mag = std::sqrt(center.x * center.x + center.y * center.y);
            if (mag > boid.maxForce) 
            {
                center /= mag;
                center *= boid.maxForce;
            }
        }
    }

    return center;
}