#include "StructureElement.hpp"

class Door : public StructureElement
{
    private:
        bool is_opened;
    public:
        Door();
        Door(int x, int y);
        ~Door();
        bool is_accessible();
        void open();
        void close();
};