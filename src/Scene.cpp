#include "Scene.hpp"

#include <SFML/Graphics.hpp>

sf::RenderWindow *Scene::window = nullptr;

void Scene::setWindow(sf::RenderWindow& window)
{
    Scene::window = &window;
}

Scene::Scene() {}

Scene::~Scene() {}

int Scene::run()
{
    if(window== nullptr){
        return TERMINATE_APP;
    }

    init();
    mClock.restart();
    
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
                return TERMINATE_APP;
            }
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window->setView(sf::View(visibleArea));
            }
            auto status = readEvent(event);
            if (status != CONTINUE_SCENE)
            {
                return status;
            }
        }
        updateLogic(mClock.restart().asSeconds());
        window->clear();
        draw(*window);
        window->display();
    }
    return TERMINATE_APP;
}

void Scene::resize(unsigned width, unsigned height)
{
    window->setSize(sf::Vector2u(width, height));
}

sf::Vector2u Scene::getSize() const
{
    return window->getSize();
}
