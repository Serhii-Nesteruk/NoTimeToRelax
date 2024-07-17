#pragma once

#include "StaticMash.h"
#include "clickObserver.h"
#include "../../Subwindows/includes/ShopWindow.h" // TODO: don't use relative paths 

#include <vector>

class Map 
{
public:
    Map() = default;
    ~Map() {}

    void draw(sf::RenderWindow& window);

    void setupBackground();
    void setupSubwindows();
    void setupStaticObjects();
    void setup();

    [[nodiscard]] std::vector<StaticMash> getStaticObjects() const;
    [[nodiscard]] std::vector<ShopWindow> getShops() const;

private:
    void setupShopWindows();

private:
    std::vector<StaticMash> _staticObjects{};
    std::vector<ShopWindow> _shops{};
    sf::Sprite _background;
    sf::Texture _backgroundTexture;
    ClickObserver _clickObserver;
};