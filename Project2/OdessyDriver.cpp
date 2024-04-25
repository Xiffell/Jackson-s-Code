// CSCI 1300 Spring 2024
// Author: Lucas Garcia
// TA: Elsie Tate
// OdessyDriver.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Map.h"
#include "Entity.h"
#include "Game.h"
#include "Func.h"
using namespace std;

int main()
{

    srand(time(nullptr)); // Seed the random number generator

    // Load Playable Charactors
    const int CHARACTERS_SIZE = 4;
    Entity playable_characters[CHARACTERS_SIZE];
    if (loadCharacters("Player.txt", playable_characters, CHARACTERS_SIZE, true))
    {
        // for (int i = 0; i < CHARACTERS_SIZE; i++)
        // {
        //     cout << playable_characters[i].getName() << " loaded..." << endl;
        // }

        cout << "Playable charactors loaded successfully!" << endl;
    }
    else
    {
        cout << "Failed to load Playable characters!" << endl;
    }

    // Load Island Enemies
    const int ISLAND_ENEMY_SIZE = 7;
    Entity island_enemies[ISLAND_ENEMY_SIZE];
    if (loadCharacters("Enemy.txt", island_enemies, ISLAND_ENEMY_SIZE, true))
    {
        // for (int i = 0; i < ISLAND_ENEMY_SIZE; i++)
        // {
        //     cout << island_enemies[i].getName() << " loaded..." << endl;
        // }
        cout << "Island enemies loaded successfully!" << endl;
    }
    else
    {
        cout << "Failed to load Island enemies!" << endl;
    }

    // Load Epic Enemies
    const int EPIC_ENEMY_SIZE = 3;
    Entity epic_enemies[EPIC_ENEMY_SIZE];
    if (loadCharacters("Enemy.txt", epic_enemies, EPIC_ENEMY_SIZE, true))
    {
        // for (int i = 0; i < EPIC_ENEMY_SIZE; i++)
        // {
        //     cout << epic_enemies[i].getName() << " loaded..." << endl;
        // }

        cout << "Epic enemies loaded successfully!" << endl;
    }
    else
    {
        cout << "Failed to load Epic enemies!" << endl;
    }

    // Load Items
    const int MAX_ITEMS = 20; // Maximum number of items
    Entity items[MAX_ITEMS];
    if (loadItems("items.txt", items, MAX_ITEMS)) 
    {
        // Print loaded items
        // for (int i = 0; i < numItems; ++i) 
        // {
        //     items[i].printStats();
        //     cout << endl;
        // }

        cout << "Items loaded successfully!" << endl;
    } 
    else 
    {
        cout << "Failed to load items!" << endl;
    }

    // Test Map class
    Map map;
    map.initializeMap();
    cout << "Map initialization completed!" << endl;

    // Display Title Screen
    cout << endl
         << "Game Start:" << endl
         << "Ready Player 1:" << endl;
    printTitle("Title.txt");
    cout << endl;

    // Print starting map
    map.printMap();

    // Charactor Selection
    Entity players[2];
    int playerOne, playerTwo;

    do{
        cout << "Which charactor would you like to choose? (Player 1) Enter your selection below..." << endl;

        // Show posible options
        for (int i = 0; i < CHARACTERS_SIZE; i++)
        {
            cout << "(" << i + 1 << ") " << playable_characters[i].getName() << "  ";
        }
        cout << endl;

        if (!(cin >> playerOne))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (playerOne < 1 || playerOne > CHARACTERS_SIZE) 
        {
            cout << "Invalid choice. Please enter a number between 1 and " << CHARACTERS_SIZE << "." << endl;
        }

    } while (playerOne < 1 || playerOne > CHARACTERS_SIZE);

        cout << "Sucessfully chosen " << playable_characters[playerOne - 1].getName() << "!" << endl << endl;
        playable_characters[playerOne - 1].printStats(); cout << endl;
        players[0] = playable_characters[playerOne - 1];

    // Player two
    do{
        cout << "Which charactor would you like to choose? (Player 2) Enter your selection below..." << endl;

        // Show posible options
        for (int i = 0; i < CHARACTERS_SIZE; i++)
        {
            if (!(playable_characters[playerOne - 1].getName() == playable_characters[i].getName()))
            {
                cout << "(" << i + 1 << ") " << playable_characters[i].getName() << "  ";
            }
            else
            {
                continue;
            }
        }
        cout << endl;

        if (!(cin >> playerTwo))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (playerTwo < 1 || playerTwo > CHARACTERS_SIZE) 
        {
            cout << "Invalid choice. Please enter a number between 1 and " << CHARACTERS_SIZE << "." << endl;
        }

    } while (playerTwo < 1 || playerTwo > CHARACTERS_SIZE);

        cout << "Sucessfully chosen " << playable_characters[playerTwo - 1].getName() << "!" << endl << endl;
        playable_characters[playerTwo - 1].printStats(); cout << endl;
        players[1] = playable_characters[playerTwo - 1];

    // Start of Shop



    return 0;
}