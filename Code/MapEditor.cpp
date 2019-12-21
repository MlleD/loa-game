#include "MapEditor.hpp"

using namespace std;

static const int MAX_WIDHT = 20;
static const int MAX_HEIGHT = 20;
static const int MIN_WIDHT = 5;
static const int MIN_HEIGHT = 5;

//Charge le fichier board si existant 
static Map open_board(const string board_file_path)
{
    try {
        Map map = MapLoader::get_map(board_file_path);
        return map;
    }
    catch(const std::exception& e)
    {
        if (string(e.what()).compare(string("Empty file")) == 0)
        {
            cout << e.what() << endl;
            cout << "Creation d'une nouvelle map." << endl;
            int height = 0;
            while (height >= MIN_HEIGHT && height <= MAX_HEIGHT)
            {
                cout << "Choisissez la hauteur du plateau entre " << MIN_HEIGHT << " et " << MAX_HEIGHT << endl;
                cin >> height;
            }
            int width = 0;
            while (width >= MIN_WIDHT && width <= MAX_WIDHT)
            {
                cout << "Choisissez la largeur du plateau entre " << MIN_WIDHT << " et " << MAX_WIDHT << endl;
                cin >> width;
            }
            return Map(MapBuilder(height,width));
        }
        else
        {
            throw;
        }
    }
}

static void map_edition(Map map)
{
    map.print();
}

//création puis edition d'un fichier.game écrase l'ancien fichier si existant.
static void game_edition(const string game_file_path, const vector<Map> maps)
{
    cout << "Creation d'un nouveau jeu." << endl;
    cout << "L'ordre des maps est celui dans lequel elles ont été données en paramètre." << endl;
    cout << "Attention : le joueur doit impérativement être situé dans le premier fichier .board et nul part ailleurs." << endl;
    int map_number = maps.size();
    int teleport_number = -1;
    while (teleport_number < 0)
    {
        cout << "Combien de teleport aura le joueur au début de la partie ?" << endl;
        cin >> teleport_number;
    }
    Game game(map_number,maps,1,teleport_number);
    GameLoader::save(game,game_file_path);
    cout << "Jeu sauvegardé avec succès dans le fichier " << game_file_path << endl;
}

//Fait office de controleur mais aussi d'interface simplifié via le terminal
int main(int argc, char const *argv[])
{
    if (argc < 2)//aucun argument
    {
        cerr  << "Au moins un fichier .board est necessaire ou un fichier .game suivit d'une liste non vide de fichiers .board" << endl;
        return -1;
    }
    if (argc == 2)//un seul argument 
    {
        string file_path = string(argv[1]);
        if (file_path.substr(file_path.size() - 6, 6).compare(string(".board")) == 0)// -> on verifie si c'est bien un .board
        {
            try
            {
                Map map = open_board(file_path);
                map_edition(map);
            }
            catch(const exception& e)
            {
                cerr << "Erreur pendant le chargement du fichier " << file_path << " : " << e.what() << endl;
                return -1;
            }
        }
        else
        {
            cerr  << "Le fichier n'a pas l'extension .board" << endl;
            return -1;
        }
    }
    else
    {
        string game_file = string(argv[1]);
        if (game_file.substr(game_file.size() - 5, 5).compare(string(".game")) == 0)// -> on verifie si c'est bien un .game
        {
            vector<Map> maps;
            for (int i = 2; i < argc; i++)
            {
                string file_path = string(argv[i]);
                if (file_path.substr(file_path.size() - 6, 6).compare(string(".board")) == 0)// -> on verifie si c'est bien un .board
                {
                    try
                    {
                        Map map = MapLoader::get_map(file_path);
                        map.set_file_path(file_path);
                        maps.push_back(map);
                    }
                    catch(const exception& e)
                    {
                        cerr << file_path << " : " << e.what() << endl;
                        return -1;
                    }
                }
                else
                {
                    cerr << file_path << " n'a pas l'extension .board" << endl;
                    return -1;
                }
            }
            game_edition(game_file, maps);
        }
        else
        {
            cerr  << "Le premier fichier n'a pas l'extension .game" << endl;
            return -1;
        }
    }
    return 0;
}