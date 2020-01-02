#ifndef WARP_H
#define WARP_H

#include "InteractiveElement.hpp"
class Warp : public InteractiveElement
{
    private:
    public:
        Warp();
        Warp(int x, int y);
        ~Warp();
        void interact(Game* game);
        static Symbole warp_symbol()
        {
            return 'p';
        }
};
#endif
