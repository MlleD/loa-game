#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameElement.hpp"

class GameObject : public virtual GameElement
{
    private:
    public:
        GameObject();
        virtual ~GameObject();
};
#endif
