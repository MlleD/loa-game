#include "Teleporter.hpp"
#include "Game.hpp"

using namespace std;

Teleporter::Teleporter()
{
    s = teleporter_symbol();
    visible = true;
}

Teleporter::Teleporter(int x, int y) : InteractiveElement(x,y)
{
    s = teleporter_symbol();
    visible = true;
}

Teleporter::~Teleporter()
{}

void Teleporter::interact(Game* game)
{
    game->set_teleport_number(game->get_teleport_number()+1);
    cout << "Vous obtenez un teleporteur : " << game->get_current_map() << " en inventaire" << endl;
}