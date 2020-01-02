#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "InteractiveElement.hpp"

class Teleporter : public InteractiveElement
{
    private:
    public:
        Teleporter();
        ~Teleporter();
        void interact(const Game* game);
};
#endif

