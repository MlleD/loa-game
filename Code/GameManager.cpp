#include <iostream>
#include <cstdlib>

#include "Map.hpp"

int main(int argc, char const *argv[])
{
    const int NB_ARGS = 3;
    if (argc != NB_ARGS)
    {
        std::cerr << (NB_ARGS - 1) << " arguments (hauteur, largeur du plateau) sont nécessaires" << std::endl;
        return -1;
    }
    if (argv[1] < 0 || argv[2] < 0)
    {
        std::cerr << "Les arguments doivent être positifs" << std::endl;
        return -2;
    }
    Map Map(atoi(argv[1]), atoi(argv[2]));
    Map.print();

    return 0;
}