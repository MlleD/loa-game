#include "GameManager.hpp"
#include <iostream>
#include <cstdlib>
#include "MapBuilder.hpp"
#include <vector>

using namespace std;


bool check_victory(Game* game)
{
    //cout << "check if win" << endl;
    if (game->get_current_map() - 1 == game->get_map_number())
    {
        cout << "Bravo tu as gagné !" << endl;
        return true;
    }
    return false;
}

bool check_game_loosed(Game* game)
{
    //cout << "check if loose" << endl;
    Map* map = game->get_map(game->get_current_map()-1);
    for (int y = 0 ; y < map->get_height() ; y++)
    {
        for (int x = 0 ; x < map->get_width() ; x++)
        {
            if (map->get_creature(x,y) != nullptr && map->get_creature(x,y)->get_symbole() == 'J')
            {
                return false;
            }
        }
    }
    cout << "Oups.. tu as perdus !" << endl;
    return true;
}

void init_creatures(Map* map, vector<Creature*>& all_creatures)
{
    for(int y = 0; y < map->get_height(); y++)
    {
        for(int x = 0; x < map->get_width(); x++)
        {
            Creature* creature = map->get_creature(x,y);
            if (creature != nullptr)
            {
                all_creatures.push_back(creature);
            }
        }
    }
}

static void remove_creature(vector<Creature*>& creatures, Creature* c)
{
    for (auto i = creatures.begin(); i< creatures.end(); i++)
    {
        if (*i == c)
        {
            creatures.erase(i);
        }
    }
}

static void play_one_turn(Game* game)
{
    cout << "play one turn" << endl;
    Map* map = game->get_map(game->get_current_map()-1);
    vector<Creature*> all_creatures;
    init_creatures(map, all_creatures);
    //cout << "creature number : " << all_creatures.size() << endl;
    for (int i = 0; i< all_creatures.size();i++)
    {
        Creature* c = all_creatures.at(i);
        if (c == nullptr)
        {
            continue;
        }
        c->print();
        cout << " at position : ";
        c->get_position()->print();
        Position* pos = c->wich_move(game);
        cout << " position choosed :";
        pos->print();
        if (map->get_creature(pos->get_x(),pos->get_y()) != nullptr && map->get_creature(pos->get_x(),pos->get_y()) != c)
        {
            remove_creature(all_creatures,map->get_creature(pos->get_x(),pos->get_y()));
        }
        map->move_creature(c->get_position(),pos);//delete la creature à la destination si existante
        c->move_to(pos);
        InteractiveElement* interactive = map->get_interactive(pos->get_x(), pos->get_y());
        if (interactive != nullptr && c->get_symbole() == 'J')
        {
            interactive->interact(game);
            delete interactive;//on consume l'objet une fois utilisé
            map->set_interactive(pos->get_x(), pos->get_y(), nullptr);
        }
        delete pos;
    }
}

static void play(Game* game)
{
    cout << "2" << endl;
    while (true) //infinite loop
    {
        if (check_victory(game) || check_game_loosed(game))
        {
            cout << "Game finished" << endl;
            return;
        }
        play_one_turn(game);
    }
    
}

//Charge le fichier board si existant 
static Map* open_board(const string board_file_path)
{
    try {
        Map *map = MapLoader::get_map(board_file_path);
        return map;
    }
    catch(const std::exception& e)
    {
        throw;
    }
}

int main(int argc, char const *argv[])
{
    if (argc < 2)//aucun argument
    {
        cerr  << "Un fichier .board ou un fichier .game est necessaire" << endl;
        return -1;
    }
    if (argc == 2)//un seul argument 
    {
        string file_path = string(argv[1]);
        if (file_path.substr(file_path.size() - 6, 6).compare(string(".board")) == 0)// -> on verifie si c'est bien un .board
        {
            try
            {
                Map *map = open_board(file_path);
                vector<Map*> maps;
                maps.push_back(map);
                Game* game = new Game(1,maps);
                play(game);
                delete game;
                return 0;
            }
            catch(const exception& e)
            {
                cerr << "Erreur pendant le chargement du fichier " << file_path << " : " << e.what() << endl;
                return -1;
            }
        }
        if (file_path.substr(file_path.size() - 5, 5).compare(string(".game")) == 0)// -> on verifie si c'est bien un .board
        {
            try
            {
                //chargement du fichier game
                Game* game = GameLoader::get_game(file_path);
                play(game);
                delete game;
                return 0;
            }
            catch(const exception& e)
            {
                cerr << "Erreur pendant le chargement du fichier " << file_path << " : " << e.what() << endl;
                return -1;
            }
        }
        else
        {
            cerr  << "Le fichier n'a pas l'extension .board ou .game" << endl;
            return -1;
        }
    }
    else
    {
        cerr  << "Seul un fichier .board ou un fichier .game est necessaire" << endl;
        return -1;
    }
    return 0;
}