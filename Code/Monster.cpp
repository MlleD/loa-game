#include "Monster.hpp"
#include "Map.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include <iostream>


using namespace std;


Monster::Monster()
{
    s = monster_symbol();
    visible = true;
}


Monster::Monster(int x, int y) : Creature(x,y)
{
    s = monster_symbol();
    visible = true;
}

Monster::~Monster()
{}

static void get_player_position(const Map* map, int& p_x, int& p_y)
{
    for (int y = 0; y < map->get_height(); y++)
    {
        for (int x = 0; x < map->get_width(); x++)
        {
            if (map->get_creature(x,y) != nullptr && map->get_creature(x,y)->get_symbole() == Player::player_symbol())
            {
                p_x = x;
                p_y = y;
                return;
            }
        }
    }
}

vector<Position*> Monster::possible_movements(const Map* map)
{
    vector<Position*> positions;
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1 ; y < 2 ; y++)
        {
            try
            {
                if (map->get_structure(Monster::pos->get_x()+x,Monster::pos->get_y()+y)->is_accessible())
                {
                    Creature* c = map->get_creature(Monster::pos->get_x()+x,Monster::pos->get_y()+y);
                    if (c != nullptr && c->get_symbole() == Monster::monster_symbol())
                    {}
                    else
                    {
                        positions.push_back(new Position(Monster::pos->get_x()+x,Monster::pos->get_y()+y));
                    }
                }
            }
            catch (const invalid_argument& err)
            {}
        }
    }
    positions.push_back(new Position(Monster::pos->get_x(),Monster::pos->get_y()));
    return positions;
}

//return < 0 if distance between pos1 and x y is smaller than pos2 and x y
static int compare(Position* pos1, Position* pos2, int x, int y)
{
    int d1 = x-pos1->get_x() + y-pos1->get_y();
    int d2 = x-pos2->get_x() + y-pos2->get_y();
    return d1 - d2;
}

//choose the nearest position to the player
Position* Monster::wich_move(Game* game)
{
    Map* map = game->get_map(game->get_current_map()-1);
    vector<Position*> positions = possible_movements(map);
    if (positions.size() == 0)
    {
        throw runtime_error(string("No possible movement for the creature ") + s + string(" at x = ") + to_string(pos->get_x()) + string(" y = ") + to_string(pos->get_y()));
    }
    int p_x;
    int p_y;
    get_player_position(map, p_x, p_y);
    Position* best_position = positions.at(0);
    for (int i = 1; i < positions.size(); i++)
    {
        Position* position = positions.at(i);
        //position->print();
        if (compare(position,best_position,p_x,p_y) < 0)
        {
            delete best_position;
            best_position = position;
        }
        else
        {
            delete position;
        }
    }
    return best_position;
}