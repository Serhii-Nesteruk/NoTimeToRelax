#include "Map.h"

#include "ChaoticLemniscate.h"

void Map::draw(sf::RenderWindow &window)
{
    for (auto& obj: _staticObjects)
        obj.draw(window);
}

void Map::setupBackground() // TODO: implement me !!!
{
}

void Map::setupSubwindows()
{
    setupBackground();
    setupStaticObjects();
    setupShopWindows();
}   


void Map::setupShopWindows() // TODO: improve me !!!
{
    ShopWindow fastFoodShop = createFastFoodShop({200.f, 200.f});
    
    _shops.push_back(fastFoodShop);

    if (!_staticObjects.empty() && !_shops.empty())
        _staticObjects.at(0).addObserver(&_shops.at(0));
}

void Map::setupRoads()
{
    ChaoticLemniscate::setWindowSize(static_cast<sf::Vector2f>(_windowSize));
    LemniscateMargines::setMargineses(200.f, 200.f);
    ChaoticLemniscate::generateCurve();
}

ShopWindow Map::createFastFoodShop(const sf::Vector2f& position)
{
    ShopWindow fastFoodShop;     
    fastFoodShop.setPosition(position);
    fastFoodShop.setTexture("../Game/resources/textures/frame.jpg");
    fastFoodShop.setScale({0.9f, 0.9f});
    fastFoodShop.atachWindow(_window);

    std::vector<Product> products = createFastFoodProducts(position);

    return attachProductsToShop(fastFoodShop, products);
}

std::vector<Product> Map::createFastFoodProducts(const sf::Vector2f& position)
{
    std::vector<Product> products;

    Product burger;
    burger.setTexture("../Game/resources/textures/BurgerProductTexture.jpg");
    burger.setScale({0.5f, 0.5f});
    burger.setPosition(position);

    products.push_back(burger);

    return products;
}

ShopWindow Map::attachProductsToShop(const ShopWindow &shop, const std::vector<Product> &products)
{
    ShopWindow temp = shop;

    for (auto& product: products)
        temp.addProduct(product);

    return temp;
}

void Map::setupStaticObjects() // TODO: improve me !!!
{
    int countOfStaticObjects = 4;
    
    std::vector<sf::Vector2f> positions = ChaoticLemniscate::getCurve();

    // TODO: remove it, it is for debuging 
    for (auto& pos: positions)
    {
        std::cout << "x: " << pos.x << " y: " << pos.y << std::endl;
    }

    for (int i = 0; i < positions.size(); ++i)
    {
        StaticMash temp;
        temp.setTexture("../Game/resources/textures/HomeTexture.png")
            .setScale({0.2f, 0.2f})
            .setPosition(positions.at(i));

        _staticObjects.push_back(temp);
    }   
}

void Map::setup(std::shared_ptr<sf::RenderWindow>& window)
{
    attachWindow(window);
    setWindowSize(_window->getSize());

    setupRoads();
    setupBackground();
    setupSubwindows();
}

void Map::mouseInputHandle()
{
    if (Keyboard::checkIfRightMousePressed()) // TODO: it must be left mouse button     
        for (auto& obj: _staticObjects)
            obj.notifyObservers();
}

std::vector<StaticMash> Map::getStaticObjects() const
{
    return _staticObjects;
}

std::vector<ShopWindow> Map::getShops() const
{
    return _shops;
}

void Map::setWindowSize(const sf::Vector2u &windowSize)
{
    _windowSize = windowSize;
}

void Map::attachWindow(std::shared_ptr<sf::RenderWindow> &window)
{
    _window = window;
}
