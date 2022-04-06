#ifndef __SCENE__HPP__
#define __SCENE__HPP__

#include <SFML/Graphics.hpp>

class Scene
{
public:
    static const int TERMINATE_APP = -1;
    static const int CONTINUE_SCENE = -2;

    int run();
    virtual void init();

protected:
    Scene(sf::RenderWindow &window);
    virtual int readEvent(const sf::Event event);
    virtual void updateLogic(float dt);
    virtual void draw();
    virtual ~Scene();

private:
    sf::RenderWindow &mWindow;
    sf::Clock mClock;
};

#endif