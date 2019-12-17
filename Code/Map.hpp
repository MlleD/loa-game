#include "Case.hpp"
#include "MapBuilder.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include <vector>

#ifndef MAP_H
#define MAP_H
typedef std::vector<Case> Board;

class Map
{
private:
    const int height;
    const int width;
    const int maxIndex;
    Board matrix;
    int number_chargers;
    int number_diamonds;
    int number_monsters; 

public:
    //Map(int h, int w, int nb_monsters, int nb_diamonds, int nb_chargers);
    Map(MapBuilder builder);
    int get_height() const;
    int get_width() const;
    int get_number_monsters() const;
    int get_number_diamonds() const;
    int get_number_chargers() const;
    GameElement get(int x, int y);
    int put(int x, int y, GameElement element);

    void print();
};
#endif