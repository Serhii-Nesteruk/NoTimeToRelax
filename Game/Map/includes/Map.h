#pragma once

#include "StaticMash.h"
#include "clickObserver.h"
#include "Keyboard.h"
#include "../../Subwindows/includes/ShopWindow.h" // TODO: don't use relative paths 

#include <memory>
#include <vector>

class Map 
{
public:
    Map() : _window(nullptr) {}
    ~Map() {}

    void draw(sf::RenderWindow& window);

    void setupBackground();
    void setupSubwindows();
    void setupStaticObjects();
    void setup(std::shared_ptr<sf::RenderWindow>& window);

    void mouseInputHandle();

    [[nodiscard]] std::vector<StaticMash> getStaticObjects() const;
    [[nodiscard]] std::vector<ShopWindow> getShops() const;

    void setWindowSize(const sf::Vector2u& windowSize);
    void attachWindow(std::shared_ptr<sf::RenderWindow>& window);

private:
    void setupShopWindows();
    void setupRoads();
    [[nodiscard]] ShopWindow createFastFoodShop(const sf::Vector2f& position);
    [[nodiscard]] std::vector<Product> createFastFoodProducts(const sf::Vector2f& position);
    [[nodiscard]] ShopWindow attachProductsToShop(const ShopWindow& shop, const std::vector<Product>& products);

private:
    std::vector<StaticMash> _staticObjects{};
    std::vector<ShopWindow> _shops{};
    sf::Vector2u _windowSize{};
    sf::Sprite _background;
    sf::Texture _backgroundTexture;

    std::shared_ptr<sf::RenderWindow> _window;
};