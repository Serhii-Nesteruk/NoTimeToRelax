#pragma once

#include "clickObserver.h"
#include "Product.h"
#include "WorldObject.h"

#include <vector>

class ShopWindow : public WorldObject, public ClickObserver
{
public:
    ShopWindow() = default;
    ~ShopWindow();

    void draw(sf::RenderWindow& window) override;
    void onNotify() override;

    void atachWindow(sf::RenderWindow* window);

    [[nodiscard]] std::vector<Product> getProducts() const;

    void addProduct(const Product& product);
private:
    std::vector<Product> _products{};
    sf::RenderWindow* _window = nullptr;
};