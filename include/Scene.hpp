#ifndef __SCENE__HPP__
#define __SCENE__HPP__

#include <SFML/Graphics.hpp>

enum GameState{
    Menu,
    Game,
    Exit,
    Continue
};

class Scene
{
public:
    static const int TERMINATE_APP = -1;
    static const int CONTINUE_SCENE = -2;

    GameState run();

    static void setWindow(sf::RenderWindow& window);

protected:
    Scene();
    virtual void init() = 0;
    virtual GameState readEvent(const sf::Event event)= 0;
    virtual void updateLogic(float dt)= 0;
    virtual void draw(sf::RenderTarget& target)= 0;
    virtual ~Scene();

    void resize(unsigned width, unsigned height);
    sf::Vector2u getSize() const;
private:
    static sf::RenderWindow *window;
    sf::Clock mClock;
};

#endif