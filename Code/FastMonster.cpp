#include "FastMonster.hpp"
#include <iostream>
#include <ctime>

using namespace std;


FastMonster::FastMonster()
{
    s = fast_monster_symbol();
    visible = true;
}


FastMonster::FastMonster(int x, int y) : Monster(x,y)
{
    s = fast_monster_symbol();
    visible = true;
}

FastMonster::~FastMonster()
{}

vector<Position*> FastMonster::possible_movements(const Map* map)
{
    vector<Position*> positions;
    for (int x = -2; x < 3; x++)
    {
        for (int y = -2 ; y < 3 ; y++)
        {
            try
            {
                if (map->get_structure(FastMonster::pos->get_x()+x,FastMonster::pos->get_y()+y)->is_accessible())
                {
                    Creature* c = map->get_creature(FastMonster::pos->get_x()+x,FastMonster::pos->get_y()+y);
                    if (c != nullptr && (Monster::is_monster(c->get_symbole())))
                    {}
                    else
                    {
                        positions.push_back(new Position(FastMonster::pos->get_x()+x,FastMonster::pos->get_y()+y));
                    }
                }
            }
            catch (const invalid_argument& err)
            {}
        }
    }
    positions.push_back(new Position(FastMonster::pos->get_x(),FastMonster::pos->get_y()));
    return positions;
}

//choose a random position in the vector of possible movements
Position* FastMonster::wich_move(Game* game)
{
    Map* map = game->get_map(game->get_current_map()-1);
    vector<Position*> positions = possible_movements(map);
    if (positions.size() == 0)
    {
        throw runtime_error(string("No possible movement for the creature ") + s + string(" at x = ") + to_string(pos->get_x()) + string(" y = ") + to_string(pos->get_y()));
    }

    std::srand(std::time(nullptr));
    int random_position = std::rand() % positions.size();
    return positions.at(random_position);
}