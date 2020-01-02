#include "Map.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <math.h>

Map::Map(MapBuilder builder)
 : height(builder.get_height()), width(builder.get_width()), maxIndex(height * width - 1),
 number_chargers(builder.get_chargers()), number_diamonds(builder.get_diamonds()), number_monsters(builder.get_monsters())
 {
    // Premiere ligne, celle du haut
    for (int i = 0; i < width; i++)
    {
        Wall *w = new Wall(i,0);
        matrix.push_back(new Case(w));
    }
    
    // Lignes intermediaires
    for (int i = 1; i < height - 1; i++)
    {
        Wall *w1 = new Wall(0,i);
        matrix.push_back(new Case(w1));
        for (int j = 1; j < width - 1; j++)
        {
            Ground *g = new Ground(j,i);
            matrix.push_back(new Case(g));
        }
        Wall *w2 = new Wall(width-1, i);
        matrix.push_back(new Case(w2));
    }

    //Ligne du bas
    for (int i = 0; i < width; i++)
    {
        Wall *w = new Wall(i,height-1);
        matrix.push_back(new Case(w));
    }
}

Map::~Map()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        delete matrix.at(i);
    }
}

static std::string get_indice(int i, int str_len=3)
{
    if (i >= pow(10,str_len) )//depassement de capacité
    {
        return std::string(str_len,'9');
    }
    std::string res;
    if (i == 0)//0
    {
        res = std::string(str_len -1,' ');
        return res.append(std::string("0"));
    }
    int cpt = str_len;
    while (i/(int)pow(10,cpt-1) == 0)//on élimine les blancs en début de chaine
    {
        res.append(" ");
        cpt--;
    }
    res.append(std::to_string(i));
    return res;
}

void Map::print()
{
    std::cout << "y / x -- >" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "v  ";
    for (int x = 0; x < get_width(); x++)
    {
        std::cout << get_indice(x);
    }
    std::cout << std::endl;
    for (int y = 0; y < get_height(); y++)
    {
        std::cout << get_indice(y);
        for (int x = 0; x < get_width(); x++)
        {
            matrix[y*get_width()+ x]->print();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Map::get_height() const
{
    return height;
}

int Map::get_width() const
{
    return width;
}

StructureElement* Map::get_structure(int x, int y) const
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        throw std::invalid_argument(std::string("Index out of range"));
    }
    return matrix.at(y * Map::get_width() + x)->get_structure();
}

void Map::set_structure(int x, int y, StructureElement* element)
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        throw std::invalid_argument(std::string("Index out of range"));
    }
    matrix.at(y*get_width() + x)->set_structure(element);
}

void Map::set_structure(Position* pos, StructureElement* element)
{
    Map::set_structure(pos->get_x(),pos->get_y(),element);
}

InteractiveElement* Map::get_interactive(int x, int y) const
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        throw std::invalid_argument(std::string("Index out of range"));
    }
    return matrix.at(y * Map::get_width() + x)->get_interactive();
}

void Map::set_interactive(int x, int y, InteractiveElement* element)
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        throw std::invalid_argument(std::string("Index out of range"));
    }
    matrix.at(y*get_width() + x)->set_interactive(element);
}

void Map::set_interactive(Position* pos, InteractiveElement* element)
{
    Map::set_interactive(pos->get_x(),pos->get_y(),element);
}

Creature* Map::get_creature(int x, int y) const
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        throw std::invalid_argument(std::string("Index out of range"));
    }
    return matrix.at(y * Map::get_width() + x)->get_creature();
}

void Map::set_creature(int x, int y, Creature* element)
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        throw std::invalid_argument(std::string("Index out of range"));
    }
    matrix.at(y*get_width() + x)->set_creature(element);
}

void Map::set_creature(Position* pos, Creature* element)
{
    Map::set_creature(pos->get_x(),pos->get_y(),element);
}

int Map::get_number_monsters() const
{
    return number_monsters;
}

int Map::get_number_diamonds() const
{
    return number_diamonds;
}

int Map::get_number_chargers() const
{
    return number_chargers;
}

void Map::set_file_path(std::string file_path)
{
    Map::file_path = file_path;
}

std::string Map::get_file_path()
{
    return Map::file_path;
}


void Map::move_creature(Position* c_pos, Position* destination)
{
    if (c_pos->get_x() == destination->get_x() && c_pos->get_y() == destination->get_y())
    {
        return;
    }
    Map::set_creature(destination,Map::get_creature(c_pos->get_x(),c_pos->get_y()));
    Map::matrix.at(c_pos->get_y() * Map::get_width() + c_pos->get_x())->remove_creature();
}


void Map::consume_interactive(int x, int y)
{
    delete Map::get_interactive(x,y);
    Map::matrix.at(y * Map::get_width() + x)->remove_interactive();
}