#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H



typedef char Symbole;

class GameElement
{
protected:
    Symbole s;

public:
    GameElement();
    GameElement(const GameElement& ge);
    //virtual void print() = 0;
    void print();
};

#endif