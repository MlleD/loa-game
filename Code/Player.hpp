#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.hpp"
#include "GameLoader.hpp"
#include <vector>
class Map;
class Player : public Creature
{
    private:
        std::vector<Position*> possible_movements(const Map* map);
        Position* get_tp_destination(Game* game);
    public:
        Player();
        Player(int x, int y);
        ~Player();
        Position* wich_move(Game* game);
        //static Symbole player_symbol();
        static Symbole player_symbol()
        {
            return 'J';
        }
};

#endif