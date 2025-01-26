
#include "RuleSeperation.h"

sf::Vector2f RuleSeperation::calculateRuleVelocity(const Boid& boid, const std::vector<Boid>& others)
{
    sf::Vector2f steer(0, 0);
    int count = 0;

    float seperationDistance = 25;

    //Check for nearby neighbors in seperation distance and add them to the center.
    for (int i = 0; i < others.size(); ++i)
    {
        float x = others[i].getPosition().x - boid.getPosition().x;
        float y = others[i].getPosition().y - boid.getPosition().y;

        float distance = std::sqrt(x * x + y * y);

        if (distance > 0 && distance < seperationDistance)
        {
            //Push away from nearby neighbors depending on distance.
            sf::Vector2f diff = boid.getPosition() - others[i].getPosition();
            float mag = std::sqrt(diff.x * diff.x + diff.y * diff.y);

            if (mag > 0) 
            {
                diff /= mag;
                diff /= distance;
                steer += diff;
                ++count;
            }
        }
    }

    //If any are found get the center of them combined.
    if (count > 0) 
    {
        steer /= (float)count;
    }

    //Steer towards heading.
    float mag = std::sqrt(steer.x * steer.x + steer.y * steer.y);
    if (mag > 0) 
    {
        steer /= mag;
        steer *= boid.maxSpeed;
        steer -= boid.getVelocity();

        //Ensure new force isn't above maxForce.
        mag = std::sqrt(steer.x * steer.x + steer.y * steer.y);
        if (mag > boid.maxForce) 
        {
            steer /= mag;
            steer *= boid.maxForce;
        }
    }

    return steer;
}