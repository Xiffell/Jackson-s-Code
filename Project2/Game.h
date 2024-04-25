// CSCI 1300 Spring 2024
// Author: Lucas Garcia
// TA: Elsie Tate
// Game.h

#include <iostream>
#include "Entity.h"
#include "Structs.h"
using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    Entity _players[2];
    Entity _enemies[2];
    Entity _allPotions[10];
    Entity _allEquip[10];

    int _num_players;
    int _num_enemies;
    int _num_potions;
    int _num_equip;

public:
    Game();

    Game(Entity players[], Entity enemies[], int num_players, int num_enemies);

    int getNumPlayers();

    int getNumEnemies();

    void setPlayersList(Entity players[], int size);

    void setEnemiesList(Entity enemies[], int size);

    bool setPlayer(int index, Entity new_player);

    bool setEnemy(int index, Entity new_enemy);

    Entity getPlayer(string name);

    Entity getEnemy(string name);

    int findPlayer(string name);

    int findEnemy(string name);

    void printAllStats();

    int combat(Entity player, Entity getEnemy);

    void shop(Potion all_potions[], Equipment all_equip[]);

    // Create and display Shop Menu
    void Game::createShop(Entity players[], Entity items[], int player_num, int numitems);
};

#endif