#include "MapLoader.hpp"
#include <fstream>

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
        //todo: generate an Exception
    cout << "Unknow symbol : " << symbol << endl;
    GameElement elt;
    return elt;
}

Map MapLoader::get_map (string file_path)
{
    int width = 0;
    int height = 0;
    ifstream file (file_path);
    string line;
    if (file.is_open())
    {
        //on récupère la largeur du plateau dans la première ligne
        if ( getline (file, line) )
        {
            try 
            {
                width = stoi(line);
            }
            catch (invalid_argument const &e)
            {
        //todo: generate an Exception
                cout << "Bad input: std::invalid_argument thrown" << endl;
            }
            catch (out_of_range const &e)
            {
        //todo: generate an Exception
                cout << "Integer overflow: std::out_of_range thrown" << endl;
            }
        }
        //on récupère la hauteur du plateau dans la seconde ligne
        if ( getline (file, line) )
        {
            try 
            {
                height = stoi(line);
            }
            catch (invalid_argument const &e)
            {
        //todo: generate an Exception
                cout << "Bad input: std::invalid_argument thrown" << endl;
            }
            catch (out_of_range const &e)
            {
        //todo: generate an Exception
                cout << "Integer overflow: std::out_of_range thrown" << endl;
            }
        }
        Map map(height, width);
        int y = 0;
        while ( y < height && getline (file, line) )
        {
            if ( line.length() != width )
            {
        //todo: generate an Exception
                cout << "A line has a wrong widht" << endl;
            }
            for (int x = 0; x < line.length(); x++)
            {
                GameElement elt = get_game_element(line[x]);
                map.put(x,y,elt);
            }
            y++;
        }
        if (y < height || getline(file, line))
        {
        //todo: generate an Exception
            cout << "Wrong height number" << endl;
        }
        file.close();
        return map;
    }
    else 
    {
        //todo: generate an Exception
        cout << "Unable to open file" << endl;
        return Map(0,0);
    }
}

void MapLoader::save(Map map, string file_path)
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
        //todo: generate an Exception
        cout << "Unable to open file : " << file_path << endl;
    }
}