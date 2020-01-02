#ifndef GAME
#define GAME
#include "Map.hpp"
#include <vector>
class Map;

class Game
{
private:
    int map_number;
    std::vector<Map*> maps;
    int current_map;//la map ou se situe le joueur
    int teleport_number;
    void set_maps(std::vector<Map*> maps);
public:
    Game();
    Game(int map_number, std::vector<Map*> maps);
    Game(int map_number, std::vector<Map*> maps, int current_map, int teleport_number);
    ~Game();
    int get_map_number() const;
    void set_map_number(int map_number);
    int get_current_map() const;
    void set_current_map(int current_map);
    int get_teleport_number() const;
    void set_teleport_number(int teleport_number);
    Map* get_map(int i) const;
    void update_teleport_number(int x);
};
#endif