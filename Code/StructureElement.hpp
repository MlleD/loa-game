#ifndef STRUCTURE_ELEMENT
#define STRUCTURE_ELEMENT
#include "GameElement.hpp"
class StructureElement : public virtual GameElement
{
private:
public:
    StructureElement();
    StructureElement(int x, int y);
    ~StructureElement();
    virtual bool is_accessible() const;
};
#endif
