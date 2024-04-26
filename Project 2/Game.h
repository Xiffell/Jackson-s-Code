#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class Game
{
public:
    // Constructor
    Game();
    // return gold from defeating enemy or return -1 if the player was defeated
    int combat(Entity player, Entity enemy);
    int epicCombat(Entity player1, Entity player2);
    // fucntion that takes in potion and equip vectors than randomizes wghat is displayed on the shop menu
    void shop(Entity);
    // loads info of plaeyrs and enemies, and then creates entities using that information
    void loadEntity();
    void loadItems();
    // controls the game
    void playGame();
    void shop(vector<Equipment>,vector<Equipment>);
    Equipment* updatePotionShop(vector<Equipment>);
    Equipment* updateItemShop(vector<Equipment>);

private:
    Entity _players;
    Entity _enemies;
    //contains all possible potions
    vector<Equipment> _allPotions;
    //contains all possible equipment
    vector<Equipment> _allEquip;
    //contains all entities
    vector<Entity> _entities;
    Equipment _current_potion_shop[3];
    Equipment _current_item_shop[3];
    string _item_shop[2][3];
};

#endif
