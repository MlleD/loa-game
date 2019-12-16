#include "MapBuilder.hpp"

MapBuilder::MapBuilder(int _height, int _width) : height(_height), width(_width)
{}

MapBuilder& MapBuilder::set_chargers(int nb)
{
    number_chargers = nb;
    return *this;
}

MapBuilder& MapBuilder::set_diamonds(int nb)
{
    number_diamonds = nb;
    return *this;
}

MapBuilder& MapBuilder::set_monsters(int nb)
{
    number_monsters = nb;
    return *this;
}

int MapBuilder::get_height() const
{
    return height;
}

int MapBuilder::get_width() const
{
    return width;
}

int MapBuilder::get_chargers()
{
    return number_chargers;
}

int MapBuilder::get_diamonds()
{
    return number_diamonds;
}

int MapBuilder::get_monsters()
{
    return number_monsters;
}

void MapBuilder::create() {}
