#include "MapEditor.hpp"
#include <iostream>
#include <cstdlib>



int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr  << "Un fichier .board est necessaire" << std::endl;
        return -1;
    }

    try {
        Map m = MapLoader::get_map(argv[1]);
        m.print();
    }
    catch(const std::exception& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }

    return 0;
}