#ifndef GROUND
#define GROUND
#include "StructureElement.hpp"

class Ground : public StructureElement
{
    private:
        
    public:
        Ground();
        Ground(int x, int y);
        ~Ground();
        bool is_accessible() const;
};
#endif