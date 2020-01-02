#include "StructureElement.hpp"
#include "InteractiveElement.hpp"



class Door : public StructureElement, public InteractiveElement
{
    private:
        bool is_opened;
    public:
        Door();
        Door(int x, int y);
        ~Door();
        bool is_accessible() const;
        void interact(Game* game);
        void open();
        void close();
};