#include "Player.hpp"
#include "Map.hpp"
#include "Game.hpp"
#include <iostream>

using namespace std;



Player::Player() : Creature()
{
    s = player_symbol();
    visible = true;
}

Player::Player(int x, int y) : Creature(x,y)
{
    s = player_symbol();
    visible = true;
}

Player::~Player()
{}

static bool is_accessible(const Map* map, int x, int y)
{
    return (map->get_structure(x,y)->is_accessible() && (map->get_creature(x,y) == nullptr || map->get_creature(x,y)->get_symbole() == Player::player_symbol()));
}

vector<Position*> Player::possible_movements(const Map* map)
{
    vector<Position*> positions;
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1 ; y < 2 ; y++)
        {
            try
            {
                if (is_accessible(map,Player::pos->get_x()+x,Player::pos->get_y()+y))
                {
                    Position* position = new Position(Player::pos->get_x()+x,Player::pos->get_y()+y);
                    positions.push_back(position);
                }
            }
            catch (const invalid_argument& err)
            {}
        }
    }
    return positions;
}

static void print_possible_movements(const vector<Position*>& positions)
{
    cout << "Possible movement :" << endl;
    for (int i = 0; i < positions.size(); i++)
    {
        positions.at(i)->print();
        cout << " : " << i << endl;
    }
}

static void print_other_possibilities(const Game* game)
{
    int tp = game->get_teleport_number();
    if (tp > 0)
    {
        cout << "Utiliser un téléporteur (reste " << tp << ") : tp"<<endl;
    }
    cout << "Sauvegarder la partie : save"<<endl;
}

Position* Player::get_tp_destination(Game* game)
{
    Map* map = game->get_map(game->get_current_map()-1);
    string reponse;
    cout << "Choisissez la destination de votre téléportation :" <<endl;
    cout << "(Pour revenir en arrière : back)" << endl;
    int x, y;
    while (true)//valeur x
    {
        cout << "Choisissez la valeur en x :" <<endl;
        cin >> reponse;
        if (reponse.compare(string("back")) == 0 )
        {
            return wich_move(game);
        }
        try
        {
            x = stoi(reponse);
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
        cin >> reponse;
        if (reponse.compare(string("back")) == 0 )
        {
            return wich_move(game);
        }
        try
        {
            y = stoi(reponse);
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
    //on verifie la disponibilité de la destination
    if (is_accessible(map, x, y))
    {
        cout << "Téléportation..."<<endl;
        game->update_teleport_number(-1);
        return new Position(x,y);
    }
    cout << "Destination non accessible..." << endl;
    return wich_move(game);
}

static void clear(vector<Position*>& positions)
{
    for (int i = 0; i<positions.size(); i++)
    {
        delete positions.at(i);
    }
}

Position* Player::wich_move(Game* game)
{
    cout << "Au tour du joueur :"<< endl;
    Map* map = game->get_map(game->get_current_map()-1);
    map->print();
    //liste mouvement possible
    vector<Position*> positions = possible_movements(map);
    //afficher possibilités : mouvements, teleporteur, sauvegarde
    print_possible_movements(positions);
    print_other_possibilities(game);
    //analyser réponse et retourner la position choisie si valide.
    while (true)
    {
        string reponse;
        cin >> reponse;
        //save
        if (reponse.compare(string("save"))==0)
        {
            clear(positions);
            cout << "nom de sauvegarde :" <<endl;
            cin >> reponse;
            try
            {
                GameLoader::save(game, reponse.append(string(".game")));
                cout << "Partie sauvegardée dans le fichier :"<< reponse <<endl;
                return wich_move(game);
            }
            catch(const std::exception& e)
            {
                cerr << e.what() << endl;
                cout << "Erreur pedant la sauvegarde..." <<endl;
                return wich_move(game);
            }
        }//fin save
        //tp
        if (reponse.compare(string("tp"))==0)
        {
            clear(positions);
            return get_tp_destination(game);
        }//fin tp
        //choix de position possible
        try
        {
            int i = stoi(reponse);
            if (i>=0 && i < positions.size())
            {
                Position* p = positions.at(i);
                Position* res = new Position(p->get_x(),p->get_y());
                /*
                for (int j = 0; j < positions.size(); j++)//on nettoie la liste des positions
                {
                    delete positions.at(i);
                }
                */
                clear(positions);
                return res;
            }
        }
        catch(const std::exception& e)
        {
            clear(positions);
            std::cerr << e.what() << endl;
            cout << "Choix non valide..." << endl;
            return wich_move(game);
        }
        clear(positions);
        //fin choix position possible
        cout << "Choix non valide..." << endl;
        return wich_move(game);
    }
    
}