#ifndef MAP_H
#define MAP_H

#include "GameElement.hpp"
#include "Case.hpp"
#include "MapBuilder.hpp"
#include "Wall.hpp"
#include "Ground.hpp"
#include "Door.hpp"
#include "Creature.hpp"

#include <vector>
#include <string>


typedef std::vector<Case*> Board;

class Map
{
private:
    std::string file_path;
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
    ~Map();
    int get_height() const;
    int get_width() const;
    int get_number_monsters() const;
    int get_number_diamonds() const;
    int get_number_chargers() const;
    StructureElement* get_structure(int x, int y) const;
    void set_structure(int x, int y, StructureElement* element);
    void set_structure(Position* pos, StructureElement* element);
    InteractiveElement* get_interactive(int x, int y) const;
    void set_interactive(int x, int y, InteractiveElement* element);
    void set_interactive(Position* pos, InteractiveElement* element);
    Creature* get_creature(int x, int y) const;
    void set_creature(int x, int y, Creature* element);
    void set_creature(Position* pos, Creature* element);
    void set_file_path(std::string file_path);
    void move_creature(Position* c_pos, Position* destination);
    void consume_interactive(int x, int y);
    std::string get_file_path();
    void print();
};
#endif