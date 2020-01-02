#ifndef DIAMOND_H
#define DIAMOND_H

#include "InteractiveElement.hpp"
class Door;
class Map;
class Diamond : public InteractiveElement
{
    private:
        Door* get_random_door(Map* map);
    public:
        Diamond();
        Diamond(int x, int y);
        ~Diamond();
        void interact(Game* game);
        static Symbole diamond_symbol()
        {
            return '$';
        }
};
#endif
