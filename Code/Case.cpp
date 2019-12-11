#include "Case.hpp"
#include <iostream>

Case::Case(GameElement &e) : element(e)
{}

void Case::print()
{
    std::cout << "[";
    element.print();
    std::cout << "]";
}

Case::~Case() {}