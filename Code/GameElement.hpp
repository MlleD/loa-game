#ifndef POSITION_H
#define POSITION_H

class Position
{
    private:
        int x;
        int y;
    public:
        Position();
        Position(int x, int y);
        Position(Position& pos);
        ~Position();
        int get_x() const;
        int get_y() const;
        void set_x(int x);
        void set_y(int y);
        void print();
        //TODO : réussir à surcharger l'operateur ==
        bool operator==(const Position& p);
};

#endif


#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H


typedef char Symbole;

class GameElement
{
protected:
    Symbole s;
    Position* pos;
    bool visible;
public:
    GameElement();
    GameElement(int x, int y);
    /*
    GameElement(const GameElement& ge);
    */
    virtual ~GameElement();
    void print();
    Symbole get_symbole() const;
    Position* get_position() const;
    void set_position(int x, int y);
    bool is_visible() const;
};

#endif