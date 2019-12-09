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

    void print();
};
