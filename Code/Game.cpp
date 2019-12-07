#include <iostream>
#include <vector>

#include "Wall.hpp"
#include "Case.hpp"

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


Game::Game(int h, int w) : height(h), width(w), maxIndex(w*h)
{
    for (int i = 0; i < maxIndex; i++)
    {
        Case c(new Wall());
        matrix.push_back(c);
    }
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
