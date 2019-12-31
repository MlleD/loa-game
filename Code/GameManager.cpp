#include "GameManager.hpp"
#include <iostream>
#include <cstdlib>
#include "MapBuilder.hpp"

MapBuilder map_generate()
{

    int height = 5;
    int width = 6;

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
    return builder;

}

/*
 * compare le format (par exemple, l'extension de fichier.board)
 * d'une chaîne str à une extension passée en paramètre
*/
bool is_format(std::string str, std::string format) 
{
    int format_size = format.size();
    return str.substr(str.size() - format_size, format_size).compare(format) == 0;
}

int main(int argc, char const *argv[])
{
    const int NB_ARGS = 2;
    if (argc != NB_ARGS)
    {
        std::cerr << (NB_ARGS - 1) << " argument est nécessaire : fichier .board ou .game " << std::endl;
        return -1;
    }
    else
    {
        if (is_format(argv[1], ".board"))
        {
            Map* m = MapLoader::get_map(argv[1]);
            m->print();
        }
        else
        {
            std::cerr << "Argument attendu : nom de fichier suivi de l'extension .board" << std::endl;
            return EXIT_FAILURE;
        }
    }

    //MapBuilder builder = map_generate();
    //Map map(builder);
    //map.print();

    //MapLoader::save(map, "plateau2.board");

    //Map m = MapLoader::get_map("plateau2.board");
    //m.print();


    return 0;
}