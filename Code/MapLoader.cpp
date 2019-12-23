#include "MapLoader.hpp"

using namespace std;

GameElement* MapLoader::get_game_element (char symbol)
{
    if ( symbol == (' ') )
    {
        return new Ground();
    }
    if ( symbol == ('X') )
    {
        return new Wall();
    }
    if ( symbol == ('+') )
    {
        Door *door = new Door();
        door->open();
        return door;
    }
    if ( symbol == ('-') )
    {
        return new Door();
    }
    if ( symbol == ('J') )
    {
        return new Player();
    }
    if ( symbol == ('s') )
    {
        return new Monster();
    }
    throw invalid_argument(string("Unknow symbol : ") + symbol);
}

Map* MapLoader::get_map (const string file_path)
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
        else
        {
            throw runtime_error("Empty file");
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
        else
        {
            throw runtime_error("Missing : board height");
        }

        MapBuilder builder(height, width);
        Map *map = new Map(builder);
        //Parcours des symboles pour définir les éléments de la map
        int y = 0;
        while ( y < height && getline (file, line) )
        {
            if (line.at(line.size()-1) == '\r')// sous windows
            {
                line = line.substr(0,line.size()-1);
            }
            
            else if ( line.length() != width )
            {
                throw runtime_error(string("Wrong number of symbols in line ") + to_string(y) +
                    string(" found ") + to_string(line.length()) + string(" symbols but ") + to_string(width) + string(" was expected.") );
            }
            for (int x = 0; x < line.length(); x++)
            {
                try
                {
                    GameElement *elt = get_game_element(line[x]);
                    elt->set_position(x,y);
                    map->put(x,y,elt);
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
                file << map.get(x,y)->get_symbole();
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