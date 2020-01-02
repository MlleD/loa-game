#include "Warp.hpp"
#include "Game.hpp"
using namespace std;

Warp::Warp()
{
    s = warp_symbol();
    visible = false;
}

Warp::Warp(int x, int y) : InteractiveElement(x,y)
{
    s = warp_symbol();
    visible = false;
}

Warp::~Warp()
{}

void Warp::interact(Game* game)
{
    game->set_current_map(game->get_current_map()+1);
    cout << "Vous passez à la map suivante : " << game->get_current_map() << endl;
}