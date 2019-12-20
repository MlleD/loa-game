#include "MapLoader.hpp"
#include "MapBuilder.hpp"
#include <fstream>
#include <stdexcept>

#include "Wall.hpp"
#include "Ground.hpp"
#include "Door.hpp"

using namespace std;

GameElement MapLoader::get_game_element (char symbol)
{
    if ( symbol == (' ') )
    {
        Ground g;
        return g;
    }
    if ( symbol == ('X') )
    {
        Wall w;
        return w;
    }
    if ( symbol == ('+') )
    {
        Door door;
        door.open();
        return door;
    }
    if ( symbol == ('-') )
    {
        Door d;
        return d;
    }
    if ( symbol == ('J') )
    {
        Player j;
        return j;
    }
    if ( symbol == ('s') )
    {
        Monster m;
        return m;
    }
    throw invalid_argument(string("Unknow symbol : ") + symbol);
}

Map MapLoader::get_map (const string file_path)
{
    ifstream file (file_path);
    if (file.is_open())
    {
        int width = 0;
        int height = 0;
        string line;
        //on récupère la largeur du plateau dans la première ligne
        if ( getline (file, line) )
        {
            try 
            {
                width = stoi(line,nullptr);
            }
            catch(const exception &e)
            {
                throw;
            }
        }
        //on récupère la hauteur du plateau dans la seconde ligne
        if ( getline (file, line) )
        {
            try 
            {
                height = stoi(line,nullptr);
            }
            catch(const exception &e)
            {
                throw;
            }
        }

        MapBuilder builder(height, width);
        Map map(builder);
        //Parcours des symboles pour définir les éléments de la map
        int y = 0;
        while ( y < height && getline (file, line) )
        {
            if ( line.length() != width )
            {
                throw runtime_error("Wrong number of symbols in a line");
            }
            for (int x = 0; x < line.length(); x++)
            {
                try
                {
                    GameElement elt = get_game_element(line[x]);
                    elt.get_position();
                    map.put(x,y,elt);
                }
                catch(exception const& e)
                {
                    cout << string ("At x : ") << to_string(x) << string (" y : ") << to_string(y) << endl; 
                    throw;
                }
                
            }
            y++;
        }
        if (y < height || getline(file, line))
        {
            throw runtime_error("Wrong number of line");
        }
        file.close();
        return map;
    }
    else 
    {
        throw runtime_error("Unable to open the file "+file_path);
    }
}

void MapLoader::save(const Map map, const string file_path)
{
    remove(file_path.c_str());
    ofstream file (file_path);
    if (file.is_open())
    {
        int width = map.get_width();
        file << width << endl;
        int height = map.get_height();
        file << height << endl;
        for (int y = 0 ; y < height ; y++)
        {
            for (int x = 0 ; x < width ; x++)
            {
                file << map.get(x,y).get_symbole();
            }
            file << endl;
        }
        file.close();
    }
    else
    {
        throw runtime_error("Unable to open the file "+file_path);
    }
}