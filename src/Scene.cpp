#include "Scene.hpp"

#include <SFML/Graphics.hpp>
#include <exception>

sf::RenderWindow *Scene::window = nullptr;

void Scene::setWindow(sf::RenderWindow& window)
{
    Scene::window = &window;
}

Scene::Scene() {}

Scene::~Scene() {}

GameState Scene::run()
{
    if(window== nullptr){
        throw std::runtime_error("On run Scene - window is nullptr");
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
                return GameState::Exit;
            }
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window->setView(sf::View(visibleArea));
            }
            GameState status = readEvent(event);
            if (status != GameState::Continue)
            {
                return status;
            }
        }
        updateLogic(mClock.restart().asSeconds());
        window->clear();
        draw(*window);
        window->display();
    }
    return GameState::Continue;
}

void Scene::resize(unsigned width, unsigned height)
{
    window->setSize(sf::Vector2u(width, height));
}

sf::Vector2u Scene::getSize() const
{
    return window->getSize();
}
