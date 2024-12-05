#include<SFML/Graphics.hpp>
#include<iostream>
#include<random>
#include<time.h>
using namespace std;

int main()
{
    // initialize the object 
    default_random_engine randomEngine;
    randomEngine.seed(time(0));
    uniform_real_distribution<float> randRadius(10.0f,50.0f), randX(0.0f,680.0f), randY(0.0f,600.0f);
    uniform_int_distribution randPointCount(3,100), randR(0,255), randG(0,255), randB(0,255);


    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window;
    window.create(sf::VideoMode(680,600),"Shapes",sf::Style::Default,settings); // Temp object for sf::VideoMode
    window.setFramerateLimit(30);

    sf::CircleShape circle;

    // run the program as long as the window is open
    while(window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        //update

        circle.setRadius(randRadius(randomEngine));
        circle.setFillColor(sf::Color(randR(randomEngine), randG(randomEngine), randB(randomEngine)));
        circle.setPosition(randX(randomEngine),randY(randomEngine));
        circle.setPointCount(randPointCount(randomEngine));

        //window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}

/*
    the structure of the progarmm
    how to create a window
    how to create a shape
    how to the Random library
    x,y axis
    how to display things over the screen 
    difference between main loop and the event handling loop
*/