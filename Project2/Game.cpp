// CSCI 1300 Spring 2024
// Author: Lucas Garcia
// TA: Elsie Tate
// Game.cpp

#include <iostream>
#include <cmath>
#include "Game.h"
#include "Entity.h"
using namespace std;

Game::Game()
{
    _num_enemies = 0;
    _num_players = 0;
}

Game::Game(Entity players[], Entity enemies[], int num_players, int num_enemies)
{
    _num_players = (num_players > 2) ? 2 : num_players;
    _num_enemies = (num_enemies > 2) ? 2 : num_enemies;

    for (int i = 0; i < _num_players; i++)
    {
        _players[i] = players[i];
        _enemies[i] = enemies[i];
    }
}

int Game::getNumPlayers()
{
    return _num_players;
}

int Game::getNumEnemies()
{
    return _num_enemies;
}

void Game::setPlayersList(Entity players[], int size)
{
    _num_players = (size > 2) ? 2 : size;

    for (int i = 0; i < _num_players; i++)
    {
        _players[i] = players[i];
    }
}

void Game::setEnemiesList(Entity enemies[], int size)
{
    _num_enemies = (size > 2) ? 2 : size;

    for (int i = 0; i < _num_enemies; i++)
    {
        _enemies[i] = enemies[i];
    }
}

bool Game::setPlayer(int index, Entity new_player)
{
    if (index >= 0 && index < _num_players)
    {
        _players[index] = new_player;
        return true;
    }
    else
    {
        return false;
    }
}

bool Game::setEnemy(int index, Entity new_enemy)
{
    if (index >= 0 && index < _num_enemies)
    {
        _enemies[index] = new_enemy;
        return true;
    }
    else
    {
        return false;
    }
}

Entity Game::getPlayer(string name)
{
    for (int i = 0; i < _num_players; i++)
    {
        if (_players[i].getName() == name)
        {
            return _players[i];
        }
    }

    return Entity();
}

Entity Game::getEnemy(string name)
{
    for (int i = 0; i < _num_enemies; i++)
    {
        if (_enemies[i].getName() == name)
        {
            return _enemies[i];
        }
    }

    return Entity();
}

int Game::findPlayer(string name)
{
    for (int i = 0; i < _num_players; i++)
    {
        if (name == _players[i].getName())
        {
            return i;
        }
    }
    return -1;
}

int Game::findEnemy(string name)
{
    for (int i = 0; i < _num_enemies; i++)
    {
        if (name == _enemies[i].getName())
        {
            return i;
        }
    }
    return -1;          
}

void Game::printAllStats()
{
    for (int i = 0; i < _num_players; i++)
    {
        _players[i].printStats();
        cout << "----------------------------------------------" << endl;
    }

    for (int j = 0; j < _num_enemies; j++)
    {
        _enemies[j].printStats();
        cout << "----------------------------------------------" << endl;;
    }
}

void Game::createShop(Entity players[], Entity items[], int player_num, int numitems)
{
    cout << "Welcome to the Shop!" << endl;

    int choice;
    do{
        cout << "(1) Buy Weapon" << endl << "(2) Buy Potion" << endl << "(3) Leave Shop" << endl;

        // Show posible options
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice < 1 || choice > 3)
        {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }

    } while (choice < 1 || choice > 3);

    // Load Weapons Arry with items with type "D" or "S" exclude price of 0 items
    int indx = 0;
    Entity Weapons[14];
    for (int i = 0; i < numitems; i++)
    {
        if (items[i].getType() == 'W' || items[i].getType() == 'S')
        {
            if (items[i].getPrice() != 0)
            {
                Weapons[indx] = items[i];
                indx++;
            }
            else
            {
                continue;
            }
        }
        else
        {
            continue;
        }
    }

    // Load Potions Arry with items with type "P"
    int P_indx = 0;
    Entity Potions[9];
    for (int i = 0; i < numitems; i++)
    {
        if (items[i].getType() == 'P')
        {
            Weapons[P_indx] = items[i];
            P_indx++;
        }
        else
        {
            continue;
        }
    }


    switch (choice)
    {
    case 1: // Display 3 random wepons
        int rand_num1, rand_num2, rand_num3;
        rand_num1 = rand() % 15;
        // Generate second random number different from the first one
        do
        {
            rand_num2 = rand() % 15;
        } while (rand_num2 == rand_num1);
        // Generate third random number different from the first two
        do
        {
            rand_num3 = rand() % 15;
        } while (rand_num3 == rand_num1 || rand_num3 == rand_num2);

        choice = 0;
        do{
        cout << "Choose one Weapon:" << endl;
        cout << "(1) " << Weapons[rand_num1].getName() << endl;
        cout << "(2) " << Weapons[rand_num2].getName() << endl;
        cout << "(3) " << Weapons[rand_num2].getName() << endl;

        // Show posible options
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice < 1 || choice > 3)
        {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }

        } while (choice < 1 || choice > 3);

        if (choice == 1)
        {
            
        }


    case 2: // Display 3 Potions

    case 3: // Leave Shop


    }
}
