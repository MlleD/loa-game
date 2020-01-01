#ifndef INTERACTIVE_ELEMENT
#define INTERACTIVE_ELEMENT
#include "GameElement.hpp"
class Game;
class InteractiveElement : public virtual GameElement
{
    public:
        InteractiveElement();
        InteractiveElement(int x, int y);
        virtual ~InteractiveElement();
        virtual void interact(const Game* game);
};

#endif