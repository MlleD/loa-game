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
        bool is_accessible() const;
        //static Symbole wall_symbol();
        static Symbole wall_symbol()
        {
            return 'X';
        }
};
#endif