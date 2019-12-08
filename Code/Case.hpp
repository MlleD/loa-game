#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H
#include "GameElement.hpp"
#endif

class Case
{
private:
    GameElement *element;

public:
    Case(GameElement *e);
    Case(char c);
    void print();
};