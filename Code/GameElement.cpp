#include "GameElement.hpp"
#include <iostream>

GameElement::GameElement() {}
GameElement::GameElement(const GameElement& ge)
{
    s = ge.s;
}
void GameElement::print()
{
    std::cout << s;
}

Symbole GameElement::get_symbole()
{
    return s;
}