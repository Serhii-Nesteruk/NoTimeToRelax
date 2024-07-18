#pragma once

#include "StaticMash.h"
#include "clickObserver.h"
#include "Keyboard.h"
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
    void setup(const sf::Vector2f& windowSize);

    void mouseInputHandle();

    [[nodiscard]] std::vector<StaticMash> getStaticObjects() const;
    [[nodiscard]] std::vector<ShopWindow> getShops() const;

    void setWindowSize(const sf::Vector2f& windowSize);

private:
    void setupShopWindows();
    void setupRoads();
    [[nodiscard]] ShopWindow createFastFoodShop(const sf::Vector2f& position);
    [[nodiscard]] std::vector<Product> createFastFoodProducts(const sf::Vector2f& position);
    [[nodiscard]] ShopWindow attachProductsToShop(const ShopWindow& shop, const std::vector<Product>& products);

private:
    std::vector<StaticMash> _staticObjects{};
    std::vector<ShopWindow> _shops{};
    sf::Vector2f _windowSize{};
    sf::Sprite _background;
    sf::Texture _backgroundTexture;
};