#ifndef WALL
#define WALL
#include "StructureElement.hpp"

class Wall : public StructureElement
{
    private:
    public: 
        Wall();
        ~Wall();
        bool is_accessible();
};
#endif