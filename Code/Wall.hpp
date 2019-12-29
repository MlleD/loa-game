#ifndef WALL
#define WALL
#include "StructureElement.hpp"

class Wall : public StructureElement
{
    private:
    public: 
        Wall();
        Wall(int x, int y);
        ~Wall();
        bool is_accessible();
};
#endif