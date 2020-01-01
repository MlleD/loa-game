#include "StructureElement.hpp"
#include <iostream>

StructureElement::StructureElement()
{}

StructureElement::StructureElement(int x, int y) : GameElement(x,y)
{}

StructureElement::~StructureElement()
{}

bool StructureElement::is_accessible() const
{
    std::cout << "StructureElement::is_accessible()" << std::endl;
}