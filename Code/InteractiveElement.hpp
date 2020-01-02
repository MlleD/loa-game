#ifndef INTERACTIVE_ELEMENT
#define INTERACTIVE_ELEMENT
#include "GameElement.hpp"
#include <iostream>

class Game;
class InteractiveElement : public virtual GameElement
{
    public:
        InteractiveElement();
        InteractiveElement(int x, int y);
        virtual ~InteractiveElement();
        virtual void interact(Game* game);
};

#endif