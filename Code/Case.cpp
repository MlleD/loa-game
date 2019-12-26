#include "Case.hpp"
#include <iostream>

Case::Case(GameElement *e) : element(e)
{}

void Case::print()
{
    std::cout << "[";
    element->print();
    std::cout << "]";
}

Case::~Case()
{
    delete element;
}

GameElement* Case::get_element() const
{
    return element;
}

void Case::set_element(GameElement* element)
{
    delete Case::element;
    Case::element = element;
}