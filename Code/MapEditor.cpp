#include "MapEditor.hpp"

using namespace std;

static const int MAX_WIDHT = 100;
static const int MAX_HEIGHT = 100;
static const int MIN_WIDHT = 5;
static const int MIN_HEIGHT = 5;

//Charge le fichier board si existant 
static Map* open_board(const string board_file_path)
{
    try {
        Map *map = MapLoader::get_map(board_file_path);
        return map;
    }
    catch(const std::exception& e)
    {
        if (string(e.what()).compare(string("Empty file")) == 0)
        {
            cout << e.what() << endl;
            cout << "Creation d'une nouvelle map." << endl;
            int height = 0;
            while (height < MIN_HEIGHT || height > MAX_HEIGHT)
            {
                cout << "Choisissez la hauteur du plateau entre " << MIN_HEIGHT << " et " << MAX_HEIGHT << endl;
                cin >> height;
            }
            int width = 0;
            while (width < MIN_WIDHT || width > MAX_WIDHT)
            {
                cout << "Choisissez la largeur du plateau entre " << MIN_WIDHT << " et " << MAX_WIDHT << endl;
                cin >> width;
            }
            Map* map = new Map(MapBuilder(height,width));
            map->set_file_path(board_file_path);
            return map;
        }
        else
        {
            throw;
        }
    }
}

static Symbole choose_element()
{
    string response;
    while (true)
    {
        cout << "Choisissez l'élément à ajouter :" <<endl;
        cout << "(Pour revenir en arrière : back)" << endl;
        cout << "Mur : '" << Wall::wall_symbol()<< "'" <<endl;
        cout << "Sol/vide : '" << Ground::ground_symbol()<< "'" <<endl;
        cout << "Porte ouverte : '" << Door::opened_door_symbol() << "'" <<endl;
        cout << "Porte fermée : '" << Door::closed_door_symbol() << "'" <<endl;
        cout << "Diamant/clef : '" << Diamond::diamond_symbol() << "'" <<endl;
        cout << "Teleporter : '" << Teleporter::teleporter_symbol()<< "'" <<endl;
        cout << "Monstre : '" << Monster::monster_symbol()<< "'" <<endl;
        cout << "Monstre errant : '" << WanderingMonster::wandering_monster_symbol() << "'" <<endl;
        cout << "Joueur : '" << Player::player_symbol()<< "'" <<endl;
        cin >> response;
        if (response.compare(string("back")) == 0 )
        {
            throw runtime_error(string("back"));
        }
        if (response.size()!=1)
        {
            continue;
        }
        else
        {
            Symbole s = response.c_str()[0];
            if (s == Wall::wall_symbol())
            {
                return Wall::wall_symbol();
            }
            if (s == Ground::ground_symbol())
            {
                return Ground::ground_symbol();
            }
            if (s == Door::opened_door_symbol())
            {
                return Door::opened_door_symbol();
            }
            if (s == Door::closed_door_symbol())
            {
                return  Door::closed_door_symbol();
            }
            if (s == Diamond::diamond_symbol())
            {
                return Diamond::diamond_symbol();
            }
            if (s == Teleporter::teleporter_symbol())
            {
                return Teleporter::teleporter_symbol();
            }
            if (s == Monster::monster_symbol())
            {
                return Monster::monster_symbol();
            }
            if (s == WanderingMonster::wandering_monster_symbol())
            {
                return WanderingMonster::wandering_monster_symbol();
            }
            if (s == Player::player_symbol())
            {
                return Player::player_symbol();
            }
            cout << "Symbole non valide"<< endl;
            continue;
        }
    }
}

static void add_element(Map* map)
{
    string response;
    Symbole s;
    try
    {
        s = choose_element();
    }
    catch(const std::exception& e)
    {
        return map_edition(map);
    }
    map->print();
    cout << "Choisissez la position de l'élément :" <<endl;
    cout << "(Pour revenir en arrière : back)" << endl;
    int x, y;
    while (true)//valeur x
    {
        cout << "Choisissez la valeur en x :" <<endl;
        cin >> response;
        if (response.compare(string("back")) == 0 )
        {
            return map_edition(map);
        }
        try
        {
            x = stoi(response);
            if (x >= 0 && x < map->get_width())
            {
                break;
            }
            cout << "Indice en dehors de la map" <<endl;
            continue;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    while (true)//valeur y
    {
        cout << "Choisissez la valeur en y :" <<endl;
        cin >> response;
        if (response.compare(string("back")) == 0 )
        {
            return map_edition(map);
        }
        try
        {
            y = stoi(response);
            if (y >= 0 && y < map->get_width())
            {
                break;
            }
            cout << "Indice en dehors de la map" <<endl;
            continue;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    if (s == Door::closed_door_symbol())
    {
        Door* d = new Door(x,y);
        d->close();
        map->set_structure(x,y,d);
        map->set_interactive(x,y,new Warp(x,y));
    }
    else if (s == Door::opened_door_symbol())
    {
        Door* d = new Door(x,y);
        d->open();
        map->set_structure(x,y,d);
        map->set_interactive(x,y,new Warp(x,y));
    }
    else if (s == Wall::wall_symbol())
    {
        map->set_structure(x,y,new Wall(x,y));
    }
    else if (s == Ground::ground_symbol())
    {
        map->set_structure(x,y,new Ground(x,y));
    }
    else if (s == Diamond::diamond_symbol())
    {
        map->set_interactive(x,y,new Diamond(x,y));
    }
    else if (s == Teleporter::teleporter_symbol())
    {
        map->set_interactive(x,y,new Teleporter(x,y));
    }
    else if (s == Monster::monster_symbol())
    {
        map->set_creature(x,y,new Monster(x,y));
    }
    else if (s == Player::player_symbol())
    {
        map->set_creature(x,y,new Player(x,y));
    }
}

static void remove_element(Map* map)
{
    string response;
    cout << "Choisissez la position de l'élément :" <<endl;
    cout << "(Pour revenir en arrière : back)" << endl;
    int x, y;
    while (true)//valeur x
    {
        cout << "Choisissez la valeur en x :" <<endl;
        cin >> response;
        if (response.compare(string("back")) == 0 )
        {
            return map_edition(map);
        }
        try
        {
            x = stoi(response);
            if (x >= 0 && x < map->get_width())
            {
                break;
            }
            cout << "Indice en dehors de la map" <<endl;
            continue;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    while (true)//valeur y
    {
        cout << "Choisissez la valeur en y :" <<endl;
        cin >> response;
        if (response.compare(string("back")) == 0 )
        {
            return map_edition(map);
        }
        try
        {
            y = stoi(response);
            if (y >= 0 && y < map->get_width())
            {
                break;
            }
            cout << "Indice en dehors de la map" <<endl;
            continue;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    map->set_structure(x,y,new Ground(x,y));
    map->set_interactive(x,y,nullptr);
    map->set_creature(x,y,nullptr);
    cout << "Elements removed" << endl;
}

static void map_edition(Map* map)
{
    while (true)//infinite loop
    {
        map->print();
        cout << "Quels modifications voulez-vous apporter ? :" << endl;
        cout << "Ajouter un élément dans la map : add" << endl;
        cout << "Retirer un élément dans la map : rm" << endl;
        cout << "Verifier si la map est jouable : check" << endl;
        cout << "Sauvegarder la map : save" << endl;
        cout << "Quitter : quit" << endl;
        string response;
        cin >> response;
        if (response.compare(string("add")) == 0)
        {
            add_element(map);
        }
        if (response.compare(string("rm")) == 0)
        {
            remove_element(map);
        }
        else if (response.compare(string("check")) == 0)
        {
            bool test = map->is_valid();
            if (test)
            {
                cout << "La map est jouable/valide" <<endl;
            }
            else
            {
                cout << "La map n'est pas jouable/valide" << endl;
            }
        }
        else if (response.compare(string("save")) == 0)
        {
            try
            {
                MapLoader::save(map, map->get_file_path());
                cout << "Map saved" << endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << endl;
                continue;
            }
        }
        else if (response.compare(string("quit")) == 0)
        {
            return;
        }
    }
}

//création puis edition d'un fichier.game écrase l'ancien fichier si existant.
static void game_edition(const string game_file_path, vector<Map*> maps)
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
    Game* game = new Game(map_number,maps,1,teleport_number);
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
                Map* map = open_board(file_path);
                map_edition(map);
                delete map;
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
            vector<Map*> maps;
            for (int i = 2; i < argc; i++)
            {
                string file_path = string(argv[i]);
                if (file_path.substr(file_path.size() - 6, 6).compare(string(".board")) == 0)// -> on verifie si c'est bien un .board
                {
                    try
                    {
                        Map *map = MapLoader::get_map(file_path);
                        map->set_file_path(file_path);
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