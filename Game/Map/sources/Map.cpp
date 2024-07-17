#include "Map.h"

void Map::draw(sf::RenderWindow& window)
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
    ShopWindow fastFoodShop;
    fastFoodShop.setPosition({200.f, 200.f});
    fastFoodShop.setTexture("../Game/resources/textures/frame.jpg");
    fastFoodShop.setScale({0.9f, 0.9f});

    Product burger;
    burger.setTexture("../Game/resources/textures/BurgerProductTexture.jpg");
    burger.setScale({0.5f, 0.5f});
    burger.setPosition({fastFoodShop.getPosition().x + 50.f, fastFoodShop.getPosition().y + 50.f});

    fastFoodShop.addProduct(burger);

    _shops.push_back(fastFoodShop);

    _staticObjects.at(0).addObserver(&_shops.at(0));
}

void Map::setupStaticObjects() // TODO: improve me !!!
{
    int countOfStaticObjects = 4;
    float indentationX = 50.f,
        indentationY = 50.f;
  
    for (int i = 1; i <= countOfStaticObjects; ++i) 
    {
        StaticMash temp;
        temp.addObserver(&_clickObserver)
            .setTexture("../Game/resources/textures/HomeTexture.png")
            .setScale({0.2f, 0.2f});   

        switch (i) { // TODO: I think it's bad idea
            case 1:
                // left upper angle
                temp.setPosition({indentationX, indentationY})
                    .setTexture("../Game/resources/textures/FastFoodTexture.png")
                    .setScale({0.5f, 0.5f});   
                break;
            case 2:
                // right upper angle
                temp.setPosition({1050.f + indentationX, indentationY});
                break;
            case 3:
                // left bottom angle
                temp.setPosition({indentationX, 500.f  + indentationY});
                break;
            case 4:
                // right bottom
                temp.setPosition({1050.f  + indentationX, 500.f  + indentationY});
                break;
        }   
        _staticObjects.push_back(temp);
    }
}

void Map::setup()
{
    setupBackground();
    setupSubwindows();
    setupStaticObjects();
}

std::vector<StaticMash> Map::getStaticObjects() const
{
    return _staticObjects;
}

std::vector<ShopWindow> Map::getShops() const
{
    return _shops;
}
