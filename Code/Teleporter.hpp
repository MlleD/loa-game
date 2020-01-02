#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "InteractiveElement.hpp"

using namespace std;

class Teleporter : public InteractiveElement
{
    private:
    public:
        Teleporter();
        Teleporter(int x, int y);
        ~Teleporter();
        void interact(Game* game);
        static Symbole teleporter_symbol()
        {
            return '*';
        }
};
#endif

