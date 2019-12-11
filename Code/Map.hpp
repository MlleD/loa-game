#include "Case.hpp"
#include <vector>

typedef std::vector<Case> Board;

class Map
{
private:
    const int height;
    const int width;
    const int maxIndex;
    Board matrix;

public:
    Map(int h, int w);
    int get_height() const;
    int get_width() const;
    GameElement get(int x, int y);
    int put(int x, int y, GameElement element);

    void print();
};
