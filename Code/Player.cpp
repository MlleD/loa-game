#include "Player.hpp"

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

Position& Player::wich_move(const Map map)
{
    return *pos;
}