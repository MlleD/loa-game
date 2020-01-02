#include "GameLoader.hpp"

using namespace std;

Game* GameLoader::get_game(const std::string file_path)
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
            throw runtime_error(string("Empty file"));
        }

        int i = map_number;
        vector<Map*> maps;
        //on lit et génère les maps
        while ( i > 0 )
        {
            if (!getline(file, line))
            {
                throw runtime_error(string("Wrong number of map"));
            }
            if (line.at(line.size()-1) == '\r')// sous windows
            {
                line = line.substr(0,line.size()-1);
            }
            try 
            {
                Map *map = MapLoader::get_map(line);
                map->set_file_path(line);
                maps.push_back(map);
            }
            catch(const exception &e)
            {
                throw;
            }
            i--;
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
        return new Game(map_number,maps,current_map,teleport_number);
    }
    else
    {
        throw runtime_error("Unable to open the file "+file_path);
    }
}

void GameLoader::save(const Game* game, const std::string file_path)
{
    //sauvegarde des maps
    try
    {
        for (int i = 0; i < game->get_map_number(); i++)
        {
            Map* map = game->get_map(i);
            MapLoader::save(map,map->get_file_path());
        }
    }
    catch(const std::exception& e)
    {
        throw;
    }
    remove(file_path.c_str());
    ofstream file (file_path);
    if (file.is_open())
    {
        int map_number = game->get_map_number();
        file << map_number << endl;
        for (int i = 0 ; i < map_number ; i++)
        {
            Map* map = game->get_map(i);
            string board_path = map->get_file_path();
            file << board_path.c_str() << endl;
        }
        int current_map = game->get_current_map();
        file << current_map << endl;
        int teleport_number = game->get_teleport_number();
        file << teleport_number << endl;
        file.close();
    }
    else
    {
        throw runtime_error("Unable to create the file "+file_path);
    }
}
