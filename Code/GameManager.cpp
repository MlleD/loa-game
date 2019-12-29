#include "GameManager.hpp"
#include <iostream>
#include <cstdlib>
#include "MapBuilder.hpp"

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
    MapBuilder builder(height, width);

    std::cout << "Bienvenue dans le builder de map " << height << " x " << width << std::endl;
    std::cout << "Combien de monstres voulez-vous sur la map ?";
    
    std::string line;
    std::getline(std::cin, line);
    builder.set_monsters(atoi(line.c_str()));
    
    std::cout << "Combien de diamants (et donc de portes de sortie) voulez-vous ?" << std::endl;
    std::getline(std::cin, line);
    builder.set_diamonds(atoi(line.c_str()));

    std::cout << "Combien de chargeurs voulez-vous sur la map ?" << std::endl;
    std::getline(std::cin, line);
    builder.set_chargers(atoi(line.c_str()));

    Map map(builder);
    map.print();

    //MapLoader::save(map, "plateau2.board");

    //Map m = MapLoader::get_map("plateau2.board");
    //m.print();


    return 0;
}