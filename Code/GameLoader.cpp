#include "GameLoader.hpp"

using namespace std;

Game GameLoader::get_game(const std::string file_path)
{
    ifstream file (file_path);
    if (file.is_open())
    {
        //on récupère le nombre de maps
        string line;
        int map_number;
        if ( getline (file, line) )
            {
            try 
            {
                map_number = stoi(line,nullptr);
            }
            catch(const exception &e)
            {
                throw;
            }
        }
        else
        {
            //empty file
            return Game();
        }

        int i = map_number;
        vector<Map> maps;
        //on lit et génère les maps
        while ( getline(file, line) && i > 0 )
        {
            try 
            {
                Map map = MapLoader::get_map(line);
                map.set_file_path(line);
                maps.push_back(map);
            }
            catch(const exception &e)
            {
                throw;
            }
        }
        if (i != 0)
        {
            throw runtime_error(string("Wrong number of map"));
        }
        //on récupère la map du joueur
        int current_map;
        if ( getline (file, line) )
            {
            try 
            {
                current_map = stoi(line,nullptr);
            }
            catch(const exception &e)
            {
                throw;
            }
        }
        else
        {
            throw runtime_error(string("Missing : map position of the player"));
        }
        //on récupère le nombre de téléporteurs du joueur
        int teleport_number;
        if ( getline (file, line) )
            {
            try 
            {
                teleport_number = stoi(line,nullptr);
            }
            catch(const exception &e)
            {
                throw;
            }
        }
        else
        {
            throw runtime_error(string("Missing : teleport number of the player"));
        }
        return Game(map_number,maps,current_map,teleport_number);
    }
    else
    {
        //throw runtime_error("Unable to open the file "+file_path);
        //on génère un jeu vide (avec aucune map)
        return Game();
    }
}

void GameLoader::save(const Game game, const std::string file_path)
{
    remove(file_path.c_str());
    ofstream file (file_path);
    if (file.is_open())
    {
        int map_number = game.get_map_number();
        file << map_number << endl;
        vector<Map> maps = game.get_maps();
        for (int i = 0 ; i < map_number ; i++)
        {
            string file_path = maps.at(i).get_file_path();
            file << file_path << endl;
        }
        int current_map = game.get_current_map();
        file << current_map << endl;
        int teleport_number = game.get_teleport_number();
        file << teleport_number << endl;
        file.close();
    }
    else
    {
        throw runtime_error("Unable to create the file "+file_path);
    }
}
