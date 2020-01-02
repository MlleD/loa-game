#include "GameManager.hpp"
#include <iostream>
#include <cstdlib>
#include "MapBuilder.hpp"
#include <vector>

using namespace std;

int current_map_number = 0;
Map *map = nullptr;
vector<Creature *> creatures;
//vector<StructureElement*> structures;

MapBuilder map_generate()
{

    int height = 5;
    int width = 6;

    MapBuilder builder(height, width);

    std::cout << "Bienvenue dans le builder de map " << height << " x " << width << std::endl;
    std::cout << "Combien de monstres voulez-vous sur la map ?";

    std::string line;
    std::getline(std::cin, line);
    builder.set_monsters(atoi(line.c_str()));

    std::cout << "Combien de diamants (et donc de portes de sortie) voulez-vous ?" << std::endl;
    std::getline(std::cin, line);
    builder.set_diamonds(atoi(line.c_str()));

    std::cout << "Combien de chargeurs voulez-vous sur la map ?" << std::endl;
    std::getline(std::cin, line);
    builder.set_chargers(atoi(line.c_str()));
    return builder;
}

/*
 * compare le format (par exemple, l'extension de fichier.board)
 * d'une chaîne str à une extension passée en paramètre
*/
bool is_format(std::string str, std::string format)
{
    int format_size = format.size();
    return str.substr(str.size() - format_size, format_size).compare(format) == 0;
}

bool check_victory(Game *game)
{
    //cout << "check if win" << endl;
    if (game->get_current_map() - 1 == game->get_map_number())
    {
        cout << "Bravo tu as gagné !" << endl;
        return true;
    }
    return false;
}

bool check_game_loosed(Game *game)
{
    //cout << "check if loose" << endl;
    Map* map = game->get_map(game->get_current_map()-1);
    for (int y = 0 ; y < map->get_height() ; y++)
    {
        for (int x = 0; x < map->get_width(); x++)
        {
            if (map->get_creature(x,y) != nullptr && map->get_creature(x,y)->get_symbole() == 'J')
            {
                return false;
            }
        }
    }
    cout << "Oups.. tu as perdu !" << endl;
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

static void play(Game *game)
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
static Map *open_board(const string board_file_path)
{
    try
    {
        Map *map = MapLoader::get_map(board_file_path);
        return map;
    }
    catch (const std::exception &e)
    {
        throw;
    }
}

int main(int argc, char const *argv[])
{
    const int NB_ARGS = 2;
    if (argc != NB_ARGS)
    {
        std::cerr << (NB_ARGS - 1) << " argument est nécessaire : fichier .board ou .game " << std::endl;
        return -1;
    }
    else
    {
        string file_path = string(argv[1]);
        if (is_format(argv[1], ".board")) // -> on verifie si c'est bien un .board
        {
            try
            {
                Map *map = open_board(file_path);
                std::vector<Map *> maps;
                maps.push_back(map);
                Game *game = new Game(1, maps);
                play(game);
                delete game;
                return 0;
            }
            catch (const exception &e)
            {
                cerr << "Erreur pendant le chargement du fichier " << file_path << " : " << e.what() << endl;
                return -1;
            }
        }
        else if (is_format(argv[1], ".game")) // -> on verifie si c'est bien un .game
        {
            try
            {
                //chargement du fichier game
                Game *game = GameLoader::get_game(file_path);
                play(game);
                delete game;
                return 0;
            }
            catch (const exception &e)
            {
                cerr << "Erreur pendant le chargement du fichier " << file_path << " : " << e.what() << endl;
                return -1;
            }
        }
        else
        {
            cerr << "Le fichier n'a pas l'extension .board ou .game" << endl;
            return -1;
        }
    }
    return 0;
}