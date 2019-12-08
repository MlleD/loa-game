#ifndef GAMESTRUCTURE_H
#define GAMESTRUCTURE_H
#include "GameStructure.hpp"
#endif

class Door : public GameStructure
{
    private:
        bool is_opened;
    public:
        Door();
        void open();
        void close();
        void print();
};