#include "Player.hpp"
#include "Game.hpp"

Player::Player() : Creature()
{
    s = 'J';
}

Player::Player(int x, int y) : Creature(x,y)
{
    s = 'J';
}

Player::~Player()
{}

Position* Player::wich_move(const Game* game)
{
    game->get_map(game->get_current_map()-1)->print();
    return pos;
}