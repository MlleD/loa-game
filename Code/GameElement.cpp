#include "GameElement.hpp"
#include <iostream>

GameElement::GameElement() {}

GameElement::GameElement(Position& p)
{
    pos.set_x(p.get_x());
    pos.set_y(p.get_y());
}

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

Position::Position() : x(0), y(0) {}

Position::Position(int _x, int _y)
{
    set_x(_x);
    set_y(_y);
}

Position::Position(Position& pos) : Position(pos.get_x(), pos.get_y())
{}

int Position::get_x() const
{
    return x;
}

int Position::get_y() const
{
    return y;
}

void Position::set_x(int _x)
{
    x = _x;
}

void Position::set_y(int _y)
{
    y = _y;
}

void Position::print()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}