
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>

#include "Boid.h"

int main() 
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int boidsCount = 100;
    
    //Setup the window.
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Boids");
    window.setFramerateLimit(60);

    //Randomize each time.
    srand(time(NULL));

    //Spawn boids.
    std::vector<Boid> boids;
    for (int i = 0; i < boidsCount; ++i) 
    {
        boids.emplace_back(rand() % windowWidth, rand() % windowHeight);
    }

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                //Close the game when attempting to close the window.
                window.close();
            }
        }

        //Update all boids.
        for (int i = 0; i < boidsCount; ++i) 
        {
            boids[i].update(boids, windowWidth, windowHeight);
        }

        //Render the screen.
        window.clear();
        for (int i = 0; i < boidsCount; ++i) 
        {
            boids[i].render(window);
        }
        window.display();
    }

    return 0;
}