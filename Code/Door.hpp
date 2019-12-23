#include "StructureElement.hpp"

class Door : public StructureElement
{
    private:
        bool is_opened;
    public:
        Door();
        ~Door();
        bool is_accessible();
        void open();
        void close();
};