#ifndef MAPBUILDER_H
#define MAPBUILDER_H


//Inspiré du design pattern Fluent Interface

class MapBuilder
{
    private:
        const int height;
        const int width;
        int number_chargers;
        int number_diamonds;
        int number_monsters;

    public:
        MapBuilder(int height, int width);
        MapBuilder& set_chargers(int nb);
        MapBuilder& set_diamonds(int nb);
        MapBuilder& set_monsters(int nb);
        int get_height() const;
        int get_width() const;
        int get_chargers();
        int get_diamonds();
        int get_monsters();
        void create();
};

#endif