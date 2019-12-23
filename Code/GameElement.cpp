#include "GameElement.hpp"
#include <iostream>

GameElement::GameElement() {
    std::cout << "constructing1 element " << std::endl;
    pos = new Position(-1,-1);
}
/*
GameElement::GameElement(Position& p)
{
    std::cout << "constructing2 element " << std::endl;
    pos = new Position(p.get_x(),p.get_y());
}

GameElement::GameElement(const GameElement& ge)
{
    std::cout << "constructing3 element " << std::endl;
    GameElement(ge.get_position());
    s = ge.s;
}
*/
GameElement::~GameElement()
{
    std::cout << "delete element " << s << std::endl;
    delete pos;
}
void GameElement::print()
{
    std::cout << s;
}

Symbole GameElement::get_symbole() const
{
    return s;
}

Position& GameElement::get_position() const
{
    return *pos;
}

void GameElement::set_position(int x, int y)
{
    pos->set_x(x);
    pos->set_y(y);
}

Position::Position() : x(0), y(0) {}

Position::Position(int _x, int _y)
{
    set_x(_x);
    set_y(_y);
}

Position::Position(Position& pos) : Position(pos.get_x(), pos.get_y())
{}

Position::~Position() 
{
    std::cout << "delete position " << x << " " << y << std::endl ;
}

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