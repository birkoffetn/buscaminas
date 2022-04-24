#ifndef __MENU_SCENE__HPP__
#define __MENU_SCENE__HPP__

#include"Scene.hpp"
#include"constants.hpp"

#include<vector>

class MenuScene: public Scene{
public:
    MenuScene();
    void init() override;
protected:    
    virtual GameState readEvent(const sf::Event event) override;
    virtual void updateLogic(float dt) override;
    virtual void draw(sf::RenderTarget& target) override;
private:
    sf::Font mFont;
    sf::Text mTitle;
    std::vector<sf::Text> mOptions;
};

#endif