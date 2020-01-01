#ifndef CASE_H
#define CASE_H
#include "Creature.hpp"
#include "StructureElement.hpp"
#include "InteractiveElement.hpp"

class Case
{
private:
    StructureElement* structure_element;
    InteractiveElement* interactive;
    Creature* creature;

public:
    Case(StructureElement* structure);
    Case(StructureElement* structure_element, InteractiveElement* interactive, Creature* creature);
    ~Case();
    void print();
    StructureElement* get_structure() const;
    void set_structure(StructureElement* element);
    InteractiveElement* get_interactive() const;
    void set_interactive(InteractiveElement* element);
    Creature* get_creature() const;
    void set_creature(Creature* element);
    void remove_creature();
};
#endif