#include "MapLoader.hpp"

using namespace std;

StructureElement* MapLoader::get_structure_element (char symbol)
{
    if ( symbol == Ground::ground_symbol() )
    {
        return new Ground();
    }
    if ( symbol == Wall::wall_symbol() )
    {
        return new Wall();
    }
    if ( symbol == Door::opened_door_symbol() )
    {
        Door *door = new Door();
        door->open();
        return door;
    }
    if ( symbol == Door::closed_door_symbol() )
    {
        return new Door();
    }
    throw invalid_argument(string("Unknown symbol : ") + symbol);
}

Creature* MapLoader::get_creature_element (char symbol)
{
    if ( symbol == ('_') )
    {
        return nullptr;
    }
    if ( symbol == Player::player_symbol() )
    {
        return new Player();
    }
    if ( symbol == Monster::monster_symbol() )
    {
        return new Monster();
    }
    if ( symbol == WanderingMonster::wandering_monster_symbol() )
    {
        return new WanderingMonster();
    }
    throw invalid_argument(string("Unknown symbol : ") + symbol);
}

InteractiveElement* MapLoader::get_interactive_element (char symbol, Map* map, int x , int y)
{
    if ( symbol == ('_') )
    {
        return nullptr;
    }
    if ( symbol == Warp::warp_symbol() )
    {
        return new Warp();
    }
    if ( symbol == Diamond::diamond_symbol() )
    {
        return new Diamond();
    }
    if ( symbol == Teleporter::teleporter_symbol() )
    {
        return new Teleporter();
    }
    throw invalid_argument(string("Unknown symbol : ") + symbol);
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
        //Parcours des symboles pour définir les structures de la map
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
                    StructureElement *elt = get_structure_element(line[x]);
                    elt->set_position(x,y);
                    map->set_structure(x,y,elt);
                }
                catch(exception const& e)
                {
                    cout << string ("At x : ") << to_string(x) << string (" y : ") << to_string(y) << endl; 
                    throw;
                }
                
            }
            y++;
        }
        if (y < height)
        {
            throw runtime_error("Wrong number of line");
        }
        //Parcours des symboles pour définir les éléments interactifs de la map
        y = 0;
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
                    InteractiveElement *elt = get_interactive_element(line[x],map, x, y);
                    if (elt != nullptr)
                    {
                        map->set_interactive(x,y,elt);
                    }
                }
                catch(exception const& e)
                {
                    cout << string ("At x : ") << to_string(x) << string (" y : ") << to_string(y) << endl; 
                    throw;
                }
                
            }
            y++;
        }
        if (y < height)
        {
            throw runtime_error("Wrong number of line");
        }
        //Parcours des symboles pour définir les créatures de la map
        y = 0;
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
                    Creature *elt = get_creature_element(line[x]);
                    if (elt != nullptr)
                    {
                        elt->set_position(x,y);
                        map->set_creature(x,y,elt);
                    }
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
        map->set_file_path(file_path);
        return map;
    }
    else 
    {
        throw runtime_error("Unable to open the file "+file_path);
    }
}

void MapLoader::save(const Map* map, const string file_path)
{
    remove(file_path.c_str());
    ofstream file (file_path.c_str());
    if (file.is_open())
    {
        int width = map->get_width();
        file << width << endl;
        int height = map->get_height();
        file << height << endl;
        for (int y = 0 ; y < height ; y++)
        {
            for (int x = 0 ; x < width ; x++)
            {
                file << map->get_structure(x,y)->get_symbole();
            }
            file << endl;
        }
        for (int y = 0 ; y < height ; y++)
        {
            for (int x = 0 ; x < width ; x++)
            {
                if (map->get_interactive(x,y) != nullptr)
                {
                    file << map->get_interactive(x,y)->get_symbole();
                }
                else
                {
                    file << '_';
                }
            }
            file << endl;
        }
        for (int y = 0 ; y < height ; y++)
        {
            for (int x = 0 ; x < width ; x++)
            {
                if (map->get_creature(x,y) != nullptr)
                {
                    file << map->get_creature(x,y)->get_symbole();
                }
                else
                {
                    file << '_';
                }
            }
            file << endl;
        }
        file.close();
    }
    else
    {
        throw runtime_error(string("Unable to open the file ")+file_path);
    }
}