#include "GameManager.hpp"
#include <iostream>
#include <cstdlib>

#include "Wall.hpp"
#include "Case.hpp"
#include "Ground.hpp"
#include "Door.hpp"


int main(int argc, char const *argv[])
{
    const int NB_ARGS = 3;
    if (argc != NB_ARGS)
    {
        std::cerr << (NB_ARGS - 1) << " arguments (hauteur, largeur du plateau) sont nécessaires" << std::endl;
        return -1;
    }
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);

    if (height < 3 || width < 3)
    {
        std::cerr << "Les arguments hauteur et largeur du plateau doivent être supérieurs à 3" << std::endl;
        return -2;
    }
    Map map(height, width);
    map.print();

    MapLoader::save(map, "plateau2.board");

    Map m = MapLoader::get_map("plateau2.board");
    m.print();


    return 0;
}