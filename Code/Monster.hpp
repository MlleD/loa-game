#ifndef MONSTER_H
#define MONSTER_H
#include "Creature.hpp"
class Map;

class Monster : public Creature
{
    private:
        std::vector<Position*> possible_movements(const Map* map);
    protected:
        bool is_monster(Symbole s);
    public:
        Monster();
        Monster(int x, int y);
        ~Monster();
        Position* wich_move(Game* game);
        //static Symbole monster_symbol();

        static Symbole monster_symbol()
        {
            return 's';
        }
};
#endif
