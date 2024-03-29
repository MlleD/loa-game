#ifndef CREATURE_H
#define CREATURE_H

#include "GameElement.hpp"
#include <algorithm>
#include <vector>
class Game;
class Creature : public virtual GameElement
{
    private:
    public:
        Creature();
        Creature(int x, int y);
        virtual ~Creature();
        int move_to(const Position* p);
        virtual Position* wich_move(Game* game);
};

#endif
