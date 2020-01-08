#include "WanderingMonster.hpp"
#include <iostream>
#include <ctime>

using namespace std;


WanderingMonster::WanderingMonster()
{
    s = wandering_monster_symbol();
    visible = true;
}


WanderingMonster::WanderingMonster(int x, int y) : Creature(x,y)
{
    s = wandering_monster_symbol();
    visible = true;
}

WanderingMonster::~WanderingMonster()
{}

vector<Position*> WanderingMonster::possible_movements(const Map* map)
{
    vector<Position*> positions;
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1 ; y < 2 ; y++)
        {
            try
            {
                if (map->get_structure(WanderingMonster::pos->get_x() + x, WanderingMonster::pos->get_y() + y)->is_accessible())
                {
                    Creature* c = map->get_creature(WanderingMonster::pos->get_x() + x, WanderingMonster::pos->get_y() + y);
                    if (c == nullptr || c->get_symbole() == Player::player_symbol())
                    {
                        positions.push_back(new Position(WanderingMonster::pos->get_x() + x, WanderingMonster::pos->get_y() + y));
                    }
                }
            }
            catch (const invalid_argument& err)
            {}
        }
    }
    positions.push_back(new Position(WanderingMonster::pos->get_x(), WanderingMonster::pos->get_y()));
    return positions;
}

//choose a random position in the vector of possible movements
Position* WanderingMonster::wich_move(Game* game)
{
    Map* map = game->get_map(game->get_current_map() - 1);
    vector<Position*> positions = possible_movements(map);
    if (positions.size() == 0)
    {
        throw runtime_error(string("No possible movement for the creature ") + s + string(" at x = ") + to_string(pos->get_x()) + string(" y = ") + to_string(pos->get_y()));
    }

    std::srand(std::time(nullptr));
    int random_position = std::rand() % positions.size();
    return positions.at(random_position);
}