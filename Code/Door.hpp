#include "StructureElement.hpp"
#include "InteractiveElement.hpp"

#ifndef DOOR
#define DOOR


class Door : public StructureElement
{
    private:
        bool is_opened;
    public:
        Door();
        Door(int x, int y);
        ~Door();
        bool is_accessible() const;
        void open();
        void close();
        //static Symbole opened_door_symbol();
        //static Symbole closed_door_symbol();
        static Symbole opened_door_symbol()
        {
            return '+';
        }
        static Symbole closed_door_symbol()
        {
            return '-';
        }

};

#endif