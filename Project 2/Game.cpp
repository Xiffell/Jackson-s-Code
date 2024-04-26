#include <iostream>
#include "Entity.h"
#include "Game.h"
#include "Entity.cpp"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <string>

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
                    cout << "Player inventory:" << endl;
                    for (int i = 0; i < player.getInventorySize(); ++i)
                    {
                        cout << i + 1 << ". " << player.getInventoryItem(i)._name << endl;
                    }
                    cout << "Enter number of the equipment you want to swap: " << endl;
                    int index;
                    cin >> index;
                    player.swap(index - 1);
                    break;
                case 4:
                    int can_run = 0;
                    can_run = (rand() % 25) + 1;
                    if (can_run > 5)
                    {
                        in_combat = false;
                    }
                    else
                    {
                        in_combat = true;
                    }
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

Equipment *Game::updatePotionShop(vector<Equipment> allPotions)
{
    for (int i = 0; i < 3; i++)
    {
        _current_item_shop[i] = allPotions[(rand() % allPotions.size())];
    }

    return _current_potion_shop;
}

Equipment *Game::updateItemShop(vector<Equipment> allItems)
{
    for (int i = 0; i < 3; i++)
    {
        _current_item_shop[i] = allItems[(rand() % allItems.size())];
    }

    return _current_item_shop;
}

void Game::shop(Entity player)
{
    /*
    1. roll for what to display
    2. display items that can purcahse
    3. check if valid gold amount
    4. add item to inventory
    */
    // make menu
    bool in_shop = true;
    updateItemShop(_allEquip);
    updatePotionShop(_allPotions);
    while (in_shop)
    {
        int choice = 0;
        while (true)
        {
            cout << "1. Buy Equipment" << endl
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
            cout << "Welcome to the equipment shop!" << endl;
            int choice = 0;
            while (true)
            {
                cout << "1. " << _current_item_shop[0]._name << "Price: " << _current_item_shop[0]._price << endl
                     << "2. " << _current_item_shop[1]._name << "Price: " << _current_item_shop[1]._price << endl
                     << "3. " << _current_item_shop[2]._name << "Price: " << _current_item_shop[2]._price << endl;
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
                if (player.getGold() >= _current_item_shop[0]._price)
                {
                    cout << "You have bought " << _current_item_shop[0]._name << endl;
                    player.setGold(player.getGold() - _current_item_shop[0]._price);
                    cout << "Gold Remaining: " << player.getGold() << endl;
                    player.addToInventory(_current_item_shop[0]);
                    break;
                }
                else
                {
                    cout << "You don't have enough gold!!" << endl;
                    break;
                }
            }
            else if (choice == 2)
            {
                if (player.getGold() >= _current_item_shop[1]._price)
                {
                    cout << "You have bought " << _current_item_shop[1]._name << endl;
                    player.setGold(player.getGold() - _current_item_shop[1]._price);
                    cout << "Gold Remaining: " << player.getGold() << endl;
                    player.addToInventory(_current_item_shop[1]);
                    break;
                }
                else
                {
                    cout << "You don't have enough gold!!" << endl;
                    break;
                }
            }
            else if (choice == 3)
            {
                if (player.getGold() >= _current_item_shop[2]._price)
                {
                    cout << "You have bought " << _current_item_shop[2]._name << endl;
                    player.setGold(player.getGold() - _current_item_shop[2]._price);
                    cout << "Gold Remaining: " << player.getGold() << endl;
                    player.addToInventory(_current_item_shop[2]);
                    break;
                }
                else
                {
                    cout << "You don't have enough gold!!" << endl;
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            cout << "Welcome to the potion shop!" << endl;
            int choice = 0;
            while (true)
            {
                cout << "1. " << _current_potion_shop[0]._name << "Price: " << _current_potion_shop[0]._price << endl
                     << "2. " << _current_potion_shop[1]._name << "Price: " << _current_potion_shop[1]._price << endl
                     << "3. " << _current_potion_shop[2]._name << "Price: " << _current_potion_shop[2]._price << endl;
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
                if (player.getGold() >= _current_potion_shop[0]._price)
                {
                    cout << "You have bought " << _current_potion_shop[0]._name << endl;
                    player.setGold(player.getGold() - _current_potion_shop[0]._price);
                    cout << "Gold Remaining: " << player.getGold() << endl;
                    player.addToInventory(_current_potion_shop[0]);
                    break;
                }
                else
                {
                    cout << "You don't have enough gold!!" << endl;
                    break;
                }
            }
            else if (choice == 2)
            {
                if (player.getGold() >= _current_potion_shop[1]._price)
                {
                    cout << "You have bought " << _current_potion_shop[1]._name << endl;
                    player.setGold(player.getGold() - _current_potion_shop[1]._price);
                    cout << "Gold Remaining: " << player.getGold() << endl;
                    player.addToInventory(_current_potion_shop[1]);
                    break;
                }
                else
                {
                    cout << "You don't have enough gold!!" << endl;
                    break;
                }
            }
            else if (choice == 3)
            {
                if (player.getGold() >= _current_potion_shop[2]._price)
                {
                    cout << "You have bought " << _current_potion_shop[2]._name << endl;
                    player.setGold(player.getGold() - _current_potion_shop[2]._price);
                    cout << "Gold Remaining: " << player.getGold() << endl;
                    player.addToInventory(_current_potion_shop[2]);
                    break;
                }
                else
                {
                    cout << "You don't have enough gold!!" << endl;
                    break;
                }
            }
        }
        else if (choice == 3)
        {
            in_shop = false;
        }
    }
}

vector<string> split(const string &s, char delimiter)
{
    vector<string> part;
    // size_t is used to itterate over the entire string in the vector, and will iterate over all elements of the vector
    size_t start = 0;
    size_t end = s.find(delimiter);

    // loop through entire string
    while (end != string::npos /*loops as long as end doesnt equal the value string::npos(indicates delimiter was found)*/)
    {
        part.push_back(s.substr(start, end - start));
        start = end + 1;                // itterates the start int
        end = s.find(delimiter, start); // itterates to the next delimiter of the string
    }

    part.push_back(s.substr(start)); // add string to vector
    return part;
}

void Game::loadEntity()
{
    ifstream file("entity.txt");
    string line;
    vector<Entity> entities;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<string> entity_data = split(line, '|');

            // Assuming entity_data has the correct order as specified in the project description
            string name = entity_data[0];
            string type = entity_data[1];
            double hp = stod(entity_data[2]);
            double stamina = stod(entity_data[3]);
            double defense = stod(entity_data[4]);
            char condition = entity_data[5][0];
            bool advantage = entity_data[6] == "True";
            string elemental_weakness = entity_data[7];
            int gold = stoi(entity_data[8]);
            string ultimate = entity_data[11];

            // create new vectors for items
            vector<string> starting_items = split(entity_data[9], ',');
            vector<string> num_items_s = split(entity_data[10], ',');

            // loop that will convert vector of number strings to
            vector<int> num_items;
            for (const auto &item : num_items_s) // const auto doesnt modify the item variable and auto tells the compiler to fingure out the variable type, &points to the item reference and num items string is whwt aiot will be looping over
            {
                num_items.push_back(stoi(item));
            }

            Entity entity(name, type, hp, stamina, defense, condition, advantage, elemental_weakness, gold, starting_items, num_items, ultimate);
            entities.push_back(entity);
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    _entities = entities;
}
void Game::loadItems()
{
    ifstream file("items.txt"); // Open the items.txt file
    string line;
    vector<Equipment> items; // Vector to store loaded items

    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<string> item_data = split(line, '|'); // Split the line into fields

            // Assuming item_data has the correct order as specified in the project description
            string name = item_data[0];
            string description = item_data[1];
            char type = item_data[2][0]; // Convert the type character to char
            double effect_value = stod(item_data[3]);
            char element = item_data[4][0]; // Convert the element character to char
            double price = stod(item_data[5]);

            // Create a new item and add it to the vector
            Equipment item(name, description, type, effect_value, element, price);
            if (type == 'P')
            {
                _allPotions.push_back(item);
            }
            else
            {
                _allEquip.push_back(item);
            }
        }

        file.close(); // Close the file after reading
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void Game::playGame()
{
    // implement game
    bool game_on = true;
    while (game_on == true)
    {
    }
}
