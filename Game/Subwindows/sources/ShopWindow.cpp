#include "ShopWindow.h"

ShopWindow::~ShopWindow()
{
    delete _window;
    _window = nullptr;
}

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

void ShopWindow::atachWindow(sf::RenderWindow *window)
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
