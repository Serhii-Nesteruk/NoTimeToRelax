#include "Game/Core/includes/Game.h"

#include <iostream>

int main() 
{
    try
    {
        Game game(sf::Vector2f(1920.f, 1080.f), "No Time To Relax");
        game.start();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "=================" << std::endl;
        std::cerr << e.what() << '\n'   ;
        std::cerr << "=================" << std::endl;
    }

    return 0;
}
