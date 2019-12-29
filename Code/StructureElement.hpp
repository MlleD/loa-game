#ifndef GAMEELEMENT_H
#include "GameElement.hpp"
#endif

#ifndef STRUCTURE_ELEMENT
#define STRUCTURE_ELEMENT
class StructureElement : public GameElement
{
private:
public:
    StructureElement();
    StructureElement(int x, int y);
    ~StructureElement();
    virtual bool is_accessible() = 0;
};
#endif
