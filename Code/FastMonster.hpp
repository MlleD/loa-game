#ifndef FastMonster_H
#define FastMonster_H
#include "Monster.hpp"
#include "Map.hpp"
#include "Game.hpp"

class FastMonster : public Monster
{
    private:
        std::vector<Position*> possible_movements(const Map* map);
    public:
        FastMonster();
        FastMonster(int x, int y);
        ~FastMonster();
        Position* wich_move(Game* game);
        static Symbole fast_monster_symbol()
        {
            return 'r';
        }
};
#endif
