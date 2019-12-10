#include "GameStructure.hpp"

class Door : public GameStructure
{
    private:
        bool is_opened;
    public:
        Door();
        void open();
        void close();
};