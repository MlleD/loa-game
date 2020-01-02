#ifndef WARP_H
#define WARP_H

#include "InteractiveElement.hpp"
class Warp : public InteractiveElement
{
    private:
    public:
        Warp();
        ~Warp();
        void interact(const Game* game);
};
#endif
