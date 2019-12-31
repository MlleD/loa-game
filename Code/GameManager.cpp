#include "GameManager.hpp"
#include <iostream>
#include <cstdlib>
#include "MapBuilder.hpp"
#include <vector>

using namespace std;

int current_map_number = 0;
Map* map = nullptr;
vector<Creature*> creatures;
//vector<StructureElement*> structures;


bool check_victory(Game* game)
{
    cout << "check if win" << endl;
    if (game->get_current_map() == game->get_maps().size())
    {
        cout << "Bravo tu as gagné !" << endl;
        return true;
    }
    return false;
}

bool check_game_loosed(Game* game)
{
    cout << "check if loose" << endl;
    Map* map = game->get_maps().at(game->get_current_map()-1);
    for (int y = 0 ; y < map->get_height() ; y++)
    {
        for (int x = 0 ; x < map->get_width() ; x++)
        {
            if (map->get(x,y)->get_symbole() == 'J')
            {
                return false;
            }
        }
    }
    cout << "Oups.. tu as perdus !" << endl;
    return true;
}

//TODO : Faire en sorte de ne pas faire de down cast: Map devrait contenir ces listes d'elements
static void init_elements(Map* map)
{
    cout << "charging map" << endl;
    //structures.clear();
    creatures.clear();
    for (int y = 0 ; y < map->get_height() ; y++)
    {
        for (int x = 0 ; x < map->get_width() ; x++)
        {
            Symbole symbol = map->get(x,y)->get_symbole();
            if ( symbol == (' ') || symbol == ('X') || symbol == ('+') || symbol == ('-') )
            {
                //structures.push_back(dynamic_cast<StructureElement*>(map->get(x,y)));
            }
            else if ( symbol == ('J') || symbol == ('s') )
            {
                creatures.push_back(dynamic_cast<Creature*>(map->get(x,y)));
                //structures.push_back(dynamic_cast<StructureElement*>(new Ground(x,y)));
            }
            else 
            {
                throw invalid_argument(string("Unknow symbol : ") + symbol);
            }
        }
    }
}

static void play_one_turn(Game* game)
{
    map = game->get_maps().at(game->get_current_map()-1);
    current_map_number = game->get_current_map();
    init_elements(map);
    for (int i = 0; i< creatures.size();i++)
    {
        Creature* c = creatures.at(i);
        Position pos = c->wich_move(map);
        //TODO: check if the destination is interactive : door key ...
        int x = c->get_position().get_x();
        int y = c->get_position().get_y();
        map->put(pos,c);
        delete map->get(x,y);
        map->put(x,y,new Ground(x,y));
        c->move_to(pos);
    }
}

static void play(Game* game)
{
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
                delete map;
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