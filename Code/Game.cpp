#include <iostream>
#include <vector>

#include "Wall.hpp"
#include "Case.hpp"
#include "Ground.hpp"
#include "Door.hpp"

typedef std::vector<Case> Board;

class Game
{
private:
    const int height;
    const int width;
    const int maxIndex;
    Board matrix;

public:
    Game(int h, int w);
    int get_height() const;
    int get_width() const;

    void print_game();
};


Game::Game(int h, int w) : height(h), width(w), maxIndex(w*h - 1)
{
    // Premiere ligne, celle du haut
    for (int i = 0; i < width; i++)
    {
        Case c(new Wall());
        matrix.push_back(c);
    }
    
    // Lignes intermediaires
    for (int i = 1; i < height - 1; i++)
    {
        matrix.push_back(new Wall());
        for (int j = 1; j < width - 1; j++)
        {
            matrix.push_back(new Ground());
        }
        matrix.push_back(new Wall());
    }

    //Ligne du bas
        for (int i = 0; i < width; i++)
    {
        Case c(new Wall());
        matrix.push_back(c);
    }

    // Ajout d'une porte fermee, en bas a droite
    matrix[maxIndex - 1] = Case(new Door());
}

void Game::print_game()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (i % width == 0)
        {
            std::cout << std::endl;
        }
        matrix[i].print();
    }
    std::cout << std::endl;
}

#include <cstdlib>

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
    Game game(atoi(argv[1]), atoi(argv[2]));
    game.print_game();

    return 0;
}
