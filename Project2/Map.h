// CSCI 1300 Spring 2024
// Author: Lucas Garcia
// TA: Elsie Tate
// Map.h

#include <iostream>
#include <stdio.h>     
#include <stdlib.h>     
#include <time.h>
using namespace std;

#ifndef MAP_H
#define MAP_H

class Map{
    public:

    // Constructor
    Map();
    
    // Parametrized Constructor
    Map(int players_num, int size);

    //Setter-Getter pair for position on map
    void setMapPos(string value, int playerID, int index);
    string getMapPos(int playerID, int index);

    // See the defines above for color options
    void initializeMap();

    int getPlayerPos(int);

    void setPlayerPos(int,int);

    // Prints Map
    void printMap();

    private:
    string m_mapArr[2][50] = {};
    int playerpos[2] = {0,0};
};

#endif