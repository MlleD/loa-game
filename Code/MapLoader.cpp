#include "MapLoader.hpp"
#include <fstream>
#include <string>

#include "Wall.hpp"
#include "Ground.hpp"
#include "Door.hpp"

using namespace std;

GameElement MapLoader::get_game_element(String symbol)
{
    GameElement element;
    switch (symbol)
    {
    case " ":
        element = new Ground();
        break;
    case "X":
        element = new Wall();
        break;
    case "+":
        Door door = new Door()
        door.open();
        element = door;
        break;
    case "-":
        element = new Door();
        break;
    
    default:
        element = nullptr;
        cout << "Unknow symbol : " << symbol << endl;
        break;
    return element;
    }
}

Map MapLoader::get_map (string file_path)
{
    int width = 0;
    int height = 0;
    Map map = nullptr;
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
                cout << "Bad input: std::invalid_argument thrown" << endl;
            }
            catch (out_of_range const &e)
            {
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
                cout << "Bad input: std::invalid_argument thrown" << endl;
            }
            catch (out_of_range const &e)
            {
                cout << "Integer overflow: std::out_of_range thrown" << endl;
            }
        }
        map = new Map(widht, height);
        int y = 0;
        while ( y < height && getline (file, line) )
        {
            if ( line.length != widht )
            {
                cout << "A line has a wrong widht" << endl
            }
            for (int x = 0; x < line.length; x++)
            {
                GameElement elt = get_game_element(line[x]);
                map.put(x,y,elt);
            }
            y++;
        }
        if (y < height || getline(file, line))
        {
            cout << "Wrong height number" << endl;
        }
        file.close();
    }
    else 
    {
        cout << "Unable to open file" << endl;
    }
    return map;
}

void MapLoader::save(Map map, String file_path)
{
    remove(file_path);
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
                file << map.get(x,y).to_str();
            }
            file << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file : " << file_path << endl;
    }
}