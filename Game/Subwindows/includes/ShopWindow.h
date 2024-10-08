#pragma once

#include "clickObserver.h"
#include "Product.h"
#include "WorldObject.h"

#include <memory>
#include <vector>

class ShopWindow : public WorldObject, public ClickObserver
{
public:
    ShopWindow() : _window(std::make_shared<sf::RenderWindow>()) {};
    ~ShopWindow() = default;

    void draw(sf::RenderWindow& window) override;
    void onNotify() override;

    void attachWindow(std::shared_ptr<sf::RenderWindow>& window);

    [[nodiscard]] std::vector<Product> getProducts() const;

    void addProduct(const Product& product);
private:
    std::vector<Product> _products{};
    std::shared_ptr<sf::RenderWindow> _window;
};