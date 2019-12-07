#define GAMEELEMENT_H

#ifdef GAMEELEMENT_H

typedef char Symbole;

class GameElement
{
private:
    Symbole s;

public:
    GameElement();
    virtual void print() = 0;
    
};

#endif