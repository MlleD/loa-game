#ifndef MAPLOADER
#define MAPLOADER
#include "Map.hpp"
#include "GameElement.hpp"
#include <iostream>
#endif


class MapeLoader
{
private :
    static GameElement get_game_element(String symbol)
public:
    static Map get_map (String file_path);
    static void save (Map map, String file_path);
};

#endif