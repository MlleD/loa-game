#include "Diamond.hpp"
#include "StructureElement.hpp"
#include "Door.hpp"
#include "Map.hpp"
#include "Game.hpp"
using namespace std;

Diamond::Diamond()
{
    s = diamond_symbol();
    visible = true;
}

Diamond::Diamond(int x, int y) : InteractiveElement(x,y)
{
    s = diamond_symbol();
    visible = true;
}

Diamond::~Diamond()
{}

Door* Diamond::get_random_door(Map* map)
{
    for (int y = 0; y < map->get_height(); y++)
    {
        for (int x = 0; x < map->get_width(); x++)
        {
            StructureElement* structure = map->get_structure(x,y);
            if (structure != nullptr && structure->get_symbole() == Door::closed_door_symbol())
            {
                return dynamic_cast<Door*>(structure);
            }
        }
    }
    return nullptr;
}


void Diamond::interact(Game* game)
{
    Map* map = game->get_map(game->get_current_map()-1);
    Door* door = get_random_door(map);
    if (door != nullptr)
    {
        door->open();
        cout << "Vous avez dévérouillé une porte" << endl;
    }
}