#include "GameElement.hpp"
#include <iostream>

GameElement::GameElement() {}

void GameElement::print()
{
    std::cout << "Elément de jeu dont le symbole est " << s << std::endl;
}
