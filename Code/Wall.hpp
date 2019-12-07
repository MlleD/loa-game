#ifndef GAMESTRUCTURE_H
#include "GameStructure.hpp"
#endif

class Wall : public GameStructure
{
    private:
        Symbole s = 'X';
    public: 
        Wall();
        void print();
        
};