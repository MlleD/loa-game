#ifndef GROUND
#define GROUND
#include "StructureElement.hpp"

class Ground : public StructureElement
{
    private:
        
    public:
        Ground();
        ~Ground();
        bool is_accessible();
};
#endif