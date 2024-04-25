#include <iostream>
#include "Entity.h"
#include "Game.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Game::combat(Entity player, Entity enemy)
{
    /*
    1. check if player has euqipment
    2. load entities
    3. determine advantage
    4. open battle menu
    5. if attacking calculate damage done and given
    6. if using potion, use potion
    7. if swaping, swap
    8. if running roll dice and then flee then update condition so that thbe parameters are followed
    9. if player defeats monster, loot and add to inventory
    10. display option to shop
    */
    bool in_combat = true;
    bool player_has_advantage = false;
    while (in_combat)
    {
        if (player.isEquippedEmpty())
        {
            cout << "Player is not equipped" << endl;
            break;
        }

        if (player.getAdvantage() > enemy.getAdvantage())
        {
            player_has_advantage = true;
            cout << "Player has advantage" << endl;
        }
        else if (player.getAdvantage() == enemy.getAdvantage())
        {
            bool determined_advantage = false;
            while (!determined_advantage)
            {
                int playerRoll = rand() % 6 + 1; // Roll a 6-sided die for the player
                int enemyRoll = rand() % 6 + 1;  // Roll a 6-sided die for the enemy

                // Determine the combat order based on the dice rolls
                if (playerRoll > enemyRoll)
                {
                    // Player goes first
                    player_has_advantage = true;
                    cout << "Player has advantage" << endl;
                    determined_advantage = true;
                }
                else if (playerRoll < enemyRoll)
                {
                    // Enemy goes first
                    player_has_advantage = false;
                    cout << "Enemy has advantage" << endl;
                    determined_advantage = true;
                }
                else
                {
                    // In case of a tie, roll again
                    playerRoll = rand() % 6 + 1;
                    enemyRoll = rand() % 6 + 1;
                    // Repeat the process until a winner is determined
                }
            }
        }
        else
        {
            player_has_advantage = false;
        }
        bool player_turn = false;
        if (player_has_advantage)
        {
            player_turn = true;
        }

        while (player.getHP() > 0 && enemy.getHP() > 0)
        {
            if (player_turn)
            {
                // Display the player's combat menu
                cout << "Player's turn in combat." << endl;
                cout << "1. Attack" << endl;
                cout << "2. Use Potion" << endl;
                cout << "3. Swap Weapon" << endl;
                cout << "4. Attempt to Run" << endl;
                int choice;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    int hit_successful = 0;
                    hit_successful = ((rand() % 10) + 1);
                    if (hit_successful >= 2)
                    {
                        int player_damage = player.getEquippedWeaponDamage();
                        cout << "Hit successful! Deals " << player_damage << " damage!" << endl;
                        cout << "Enemy HP before :" << enemy.getHP() << endl;
                        enemy.setHP(enemy.getHP() - (player_damage * 3.5));
                        cout << "Enemy HP after :" << enemy.getHP() << endl;
                    }
                    else
                    {
                        cout << "Miss!" << endl;
                    }

                    break;
                case 2:
                    // Player uses a potion
                    // (implement use potion function here)
                    break;
                case 3:
                    // Player swaps their weapon
                    // (implement swap weapon function here)
                    break;
                case 4:
                    // Player attempts to run
                    // (implement run function here)
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                }

                // Switch turns
                player_turn = false;
            }
            else
            {
                // Enemy's turn
                cout << "Enemy's turn in combat." << endl;
                // (implement enemy's attack function here)

                // Switch turns
                player_turn = true;
            }

            // Check if either the player or the enemy's health drops below zero
            if (player.getHP() <= 0)
            {
                cout << "Player has been defeated!" << endl;
                // (implement player defeat logic here)
            }
            else if (enemy.getHP() <= 0)
            {
                cout << "Enemy has been defeated!" << endl;
                // (implement enemy defeat logic here)
            }
        }
    }
}

int Game::epicCombat(Entity player1, Entity player2)
{
    /*
    1. check for plays equipment
    2. add both players and make smae as combat func
    */
}

void Game::shop(vector<Potion> all_potions, vector<Equipment> all_equip)
{
    /*
    1. roll for what to display
    2. display items that can purcahse
    3. check if valid gold amount
    4. add item to inventory
    */
    const int num_potions = 4;
    // initaialize shop
    int rand_num = (rand() % num_potions);

    // make menu
    bool in_shop = true;
    while (in_shop)
    {
        int choice = 0;
        while (true)
        {
            cout << "1. Buy Weapon" << endl
                 << "2. Buy Potion" << endl
                 << "3. Leave Shop" << endl;
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 3)
            {
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                cin.ignore();
                break; // Input is valid, exit the loop
            }
        }

        if (choice == 1)
        {
        }
        else if (choice == 2)
        {
        }
        else if (choice == 3)
        {
            in_shop = false;
        }
    }
}

void Game::loadEnity()
{
    // load entity and stats
}

void Game::playGame()
{
    // implement game
    bool game_on = true;
    while (game_on == true)
    {
    }
}