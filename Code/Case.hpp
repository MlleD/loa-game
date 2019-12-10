#ifndef GAMEELEMENT_H
#include "GameElement.hpp"
#define GAMEELEMENT_H
#endif

#ifndef CASE_H
#define CASE_H
class Case
{
private:
    GameElement element;

public:
    Case(GameElement &e);
    void print();
    ~Case();
};
#endif