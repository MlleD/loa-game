#include "Creature.hpp"
#include <iostream>

using namespace std;

Creature::Creature()
{}

Creature::Creature(int x, int y) : GameElement(x,y)
{}

Creature::~Creature()
{}

int Creature::move_to(const Position* p)
{
    pos->set_x(p->get_x());
    pos->set_y(p->get_y());
}


Position* Creature::wich_move(Game* game)
{
    std::cout << "Creature::wich_move()" << std::endl;
}