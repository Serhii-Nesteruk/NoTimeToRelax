#include "Map.h"

#include "ChaoticLemniscate.h"

#include <algorithm>

void Map::draw(sf::RenderWindow &window)
{
    window.draw(_background);
    for (auto& obj: _staticObjects)
        obj.draw(window);
}

void Map::setupBackground() // TODO: implement me !!!
{
    loadBackground("../Game/resources/textures/background.png");
    _background.setTexture(_backgroundTexture);
    _background.setPosition(0.f, 0.f);
}

void Map::setupSubwindows()
{
    setupShopWindows();
}

void Map::resetStaticObjPosition()
{
    std::vector<sf::Vector2f> curvePoints = ChaoticLemniscate::getCurve();
    // TODO: replace it 
    for (int i = 0; i < curvePoints.size() && i < _staticObjects.size(); ++i)
        _staticObjects.at(i).setPosition(curvePoints.at(i));
}

void Map::setupShopWindows() // TODO: improve me !!!
{
    ShopWindow fastFoodShop = createFastFoodShop({200.f, 200.f});

    _shops.push_back(fastFoodShop);

    if (!_staticObjects.empty() && !_shops.empty())
        _staticObjects.at(0).addObserver(&_shops.at(0));
}

void Map::generateRoads()
{
    ChaoticLemniscate::setWindowSize(static_cast<sf::Vector2f>(_windowSize));
    LemniscateMargines::setMargineses(200.f, 200.f);
    ChaoticLemniscate::generateCurve();
}

void Map::handleWindowResize(std::shared_ptr<sf::RenderWindow>& window)
{
    attachWindow(window);
    setWindowSize(_window->getSize());
    generateRoads();
    resetStaticObjPosition();
}

ShopWindow Map::createFastFoodShop(const sf::Vector2f& position)
{
    ShopWindow fastFoodShop;     
    fastFoodShop.setPosition(position);
    fastFoodShop.setTexture("../Game/resources/textures/frame.jpg");
    fastFoodShop.setScale({0.9f, 0.9f});
    fastFoodShop.attachWindow(_window);

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

ShopWindow Map::attachProductsToShop(ShopWindow shop, const std::vector<Product> &products)
{
    std::for_each(products.begin(), products.end(), [&shop]( const Product& product ){
        shop.addProduct(product);
    });

    return shop;
}

void Map::loadBackground(const std::filesystem::path& path)
{
    if (!_backgroundTexture.loadFromFile(path.string()))
        throw std::runtime_error("Failed to load background");
}

void Map::setupStaticObjects() // TODO: improve me !!!
{
    int countOfStaticObjects = 4;
    
    std::vector<sf::Vector2f> curvePoints = ChaoticLemniscate::getCurve();

    for (int i = 0; i < curvePoints.size() && i < countOfStaticObjects; ++i)
    {
        StaticMash obj;
        obj.setTexture("../Game/resources/textures/HomeTexture.png")
            .setScale({0.2f, 0.2f})
            .setPosition(curvePoints.at(i));

        _staticObjects.push_back(obj);
    }  

    _staticObjects.at(0).addObserver(&_shops.at(0)); // TODO: remove it 
}

void Map::setup(std::shared_ptr<sf::RenderWindow>& window)
{
    attachWindow(window);
    setWindowSize(_window->getSize());

    setupBackground();
    generateRoads();
    setupSubwindows();
    setupStaticObjects();
}

void Map::mouseInputHandle() // TODO: IMPLEMENT ME!!!
{
    if (Keyboard::checkIfLeftMousePressed()) 
    {
        sf::Vector2i mouse = Keyboard::getMousePosition(*_window);
        std::for_each(_staticObjects.begin(), _staticObjects.end(), [&mouse](StaticMash& obj)
        {
            if (obj.checkIfObjWasPressed(static_cast<sf::Vector2f>(mouse))) 
                obj.notifyObservers();
        });
    }
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