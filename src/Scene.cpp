#include "Scene.hpp"

#include <SFML/Graphics.hpp>

Scene::Scene(sf::RenderWindow &window) : mWindow(window) {}

Scene::~Scene() {}

int Scene::run()
{
    init();
    
    while (mWindow.isOpen())
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mWindow.close();
            }
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                mWindow.setView(sf::View(visibleArea));
            }
            auto status = readEvent(event);
            if (status != CONTINUE_SCENE)
            {
                return status;
            }
        }
        updateLogic(mClock.restart().asSeconds());
        draw();
    }
    return TERMINATE_APP;
}

void Scene::init()
{
    mClock.restart();
}

int Scene::readEvent(const sf::Event)
{
    return CONTINUE_SCENE;
}

void Scene::updateLogic(float) {}

void Scene::draw() {}