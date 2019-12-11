#ifndef GAMEELEMENT_H
#include "GameElement.hpp"
#endif

#ifndef GAMESTRUCTURE_H
#define GAMESTRUCTURE_H
class GameStructure : public GameElement
{
private:
    bool accessibility;
public:
    GameStructure();
    //virtual bool is_accessible() = 0;
    ~GameStructure();
};
#endif
