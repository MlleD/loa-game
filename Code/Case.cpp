#include "Case.hpp"
#include <iostream>
#include <stdexcept>

Case::Case(StructureElement* structure) : structure_element(structure) , interactive(nullptr) , creature(nullptr)
{}
Case::Case(StructureElement* structure, InteractiveElement* interactive, Creature* creature) : structure_element(structure) , interactive(interactive) , creature(creature)
{}
Case::~Case()
{
    if (creature != nullptr)
    {
        delete creature;
    }
    if (interactive != nullptr)
    {
        if(interactive->get_symbole() == '+' || interactive->get_symbole() == '-')
        {
            structure_element = nullptr;
        }
        delete interactive;
    }
    if (structure_element != nullptr)
    {
        delete structure_element;
    }
}
void Case::print()
{
    if (creature != nullptr)
    {
        std::cout << "[";
        creature->print();
        std::cout << "]";
    }
    else if (interactive != nullptr)
    {
        std::cout << "[";
        interactive->print();
        std::cout << "]";
    }
    else if (structure_element != nullptr)
    {
        std::cout << "[";
        std::cout << structure_element->get_symbole();
        std::cout << "]";
    }
    else
    {
        throw std::runtime_error(std::string("case dans elements"));
    }
    
}
StructureElement* Case::get_structure() const
{
    return structure_element;
}
void Case::set_structure(StructureElement* element)
{
    if(structure_element != nullptr)
    {
        delete structure_element;
    }
    structure_element = element;
}
InteractiveElement* Case::get_interactive() const
{
    return interactive;
}
void Case::set_interactive(InteractiveElement* element)
{
    if(interactive != nullptr)
    {
        delete interactive;
    }
    interactive = element;
}
Creature* Case::get_creature() const
{
    return creature;
}
void Case::set_creature(Creature* element)
{
    if(creature != nullptr)
    {
        delete creature;
    }
    creature = element;
}

void Case::remove_creature()
{
    Case::creature = nullptr;
}