#ifndef WANDERINGMONSTER_H
#define WANDERINGMONSTER_H
#include "Monster.hpp"
#include "Map.hpp"
#include "Game.hpp"

class WanderingMonster : public Creature
{
    private:
    public:
        WanderingMonster();
        WanderingMonster(int x, int y);
        ~WanderingMonster();
        std::vector<Position*> possible_movements(const Map* map);
        Position* wich_move(Game* game);
        static Symbole wandering_monster_symbol()
        {
            return 'w';
        }
};
#endif
