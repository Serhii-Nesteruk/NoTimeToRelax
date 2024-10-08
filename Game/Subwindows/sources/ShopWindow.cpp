#include "ShopWindow.h"

void ShopWindow::draw(sf::RenderWindow &window)
{
    WorldObject::draw(window);
    for (auto& product: _products)
        product.draw(window);
}

void ShopWindow::onNotify()
{
    if (_window == nullptr)
        throw std::runtime_error("ShopWindow ERROR: Window isn't attached");
    draw(*_window);
}   

void ShopWindow::attachWindow(std::shared_ptr<sf::RenderWindow>& window)
{
    _window = window;
}

std::vector<Product> ShopWindow::getProducts() const
{
    return _products;
}

void ShopWindow::addProduct(const Product &product)
{
    _products.push_back(product);
}
