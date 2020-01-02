#ifndef DIAMOND_H
#define DIAMOND_H

#include "InteractiveElement.hpp"

class Diamond : public InteractiveElement
{
    private:
    public:
        Diamond();
        ~Diamond();
        void interact(const Game* game);
};
#endif
