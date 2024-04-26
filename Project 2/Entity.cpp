#include <iostream>
#include "Entity.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Constructor definition for default constructor
Entity::Entity()
{
    _name = "";
    _HP = 0.0;
    _stamina = 0.0;
    _defense = 0.0;
    _condition = '\0';
    _advantage = false;
    _gold = 0;
    _elemental_weakness = "";
    _starting_items = {};
    _num_items = {};
    _ultimate = "";
}

// Constructor definition for parameterized constructor
Entity::Entity(string name, string, double hp, double stamina, double defense, char condition, bool advantage, string elemental_weakness, int gold, vector<string> starting_items, vector<int> num_items, string ultimate)

{

    _name = name;
    _HP = hp;
    _stamina = stamina;
    _defense = defense;
    _condition = condition;
    _advantage = advantage;
    _gold = gold;
    _elemental_weakness = elemental_weakness;
    _starting_items = starting_items;
    _num_items = num_items;
    _ultimate = ultimate;
}

Equipment::Equipment()
{
    _name = "";
    _description = "";
    _type = '\0';
    _element = '\0';
    _effect_value = 0.0;
    _price = 0.0;
}

Equipment::Equipment(string name, string description, char type, double effect_value, char element, double price)
{
    _name = name;
    _description = description;
    _type = type;
    _element = element;
    _effect_value = effect_value;
    _price = price;
}

void Entity::setName(string name)
{
    _name = name;
}
void Entity::setHP(double HP)
{
    _HP = HP;
}
void Entity::setStamina(double stamina)
{
    _stamina = stamina;
}
void Entity::setDefence(double defense)
{
    _defense = defense;
}
void Entity::setCondition(char condition)
{
    _condition = condition;
}
void Entity::setAdvantage(bool advantage)
{
    _advantage = advantage;
}
void Entity::setGold(int gold)
{
    _gold = gold;
}

string Entity::getName() const
{
    return _name;
}
double Entity::getHP() const
{
    return _HP;
}
double Entity::getStamina() const
{
    return _stamina;
}
double Entity::getDefense() const
{
    return _defense;
}
char Entity::getCondition() const
{
    return _condition;
}
bool Entity::getAdvantage() const
{
    return _advantage;
}
int Entity::getGold() const
{
    return _gold;
}

string Entity::getUltimate() const
{
    return _ultimate;
}
void Entity::setUltimate(string ultimate)
{
    _ultimate = ultimate;
}

const vector<string> &Entity::getStartingItems() const
{
    return _starting_items;
}
void Entity::setStartingItems(vector<string> starting_items)
{
    _starting_items = starting_items;
}

const vector<int> &Entity::getNumItems() const
{
    return _num_items;
}
void Entity::setNumItems(vector<int> num_items)
{
    _num_items = num_items;
}

string Entity::getElementalWeakness() const
{
    return _elemental_weakness;
}
void Entity::setElementalWeakness(string elemental_weakness)
{
    _elemental_weakness = elemental_weakness;
}


int Entity::getInventorySize() const
{
    return _inventory.size();
}

Equipment Entity::getInventoryItem(int user_input)
{
    return _inventory[user_input];
}

// fucntion to swap what the player has equipped
void Entity::swap(int user_choice)
{
    Equipment chosenEquip = _equipped[user_choice];
    _equipped.erase(_equipped.begin() + user_choice);

    // Add the chosen equipment to the inventory vector
    _inventory.push_back(chosenEquip);
}
// function to drop weapons or items
void Entity::drop(int user_choice)
{
    Equipment chosenEquip = _equipped[user_choice];
    _equipped.erase(_equipped.begin() + user_choice);
}
void Entity::usePotion(int userChoice)
{
    Equipment usedPotion = _entity_potions[userChoice];

    // Display information about the used potion
    cout << "Using potion: " << usedPotion._name << endl;

    // Apply effects based on the potion type
    switch (usedPotion._type)
    {
    case 'H': // Health potion
        _HP += usedPotion._effect_value;
        cout << "Health increased by " << usedPotion._effect_value << endl;
        break;
    case 'S': // Stamina potion
        _stamina += usedPotion._effect_value;
        cout << "Stamina increased by " << usedPotion._effect_value << endl;
        break;
    case 'D': // Defense potion
        _defense += usedPotion._effect_value;
        cout << "Defense increased by " << usedPotion._effect_value << endl;
        break;
    case 'A':
        _advantage += usedPotion._effect_value;
    default:
        cout << "Unknown potion type!" << endl;
        break;
    }

    // Delete the used potion from the _potions vector
    _entity_potions.erase(_entity_potions.begin() + userChoice);
}


void Entity::printEntityStats(Entity entity) const
{
    cout << "Player: " << entity.getName() << endl;
    cout << "HP: " << entity.getHP() << endl;
    cout << "Stamina: " << entity.getStamina() << endl;
    cout << "Defense: " << entity.getDefense() << endl;
    cout << "Condition: " << entity.getCondition() << endl;
    cout << "Gold Held:" << entity.getGold() << endl;
}

void printEquipmentStats(Equipment equipment)
{
    cout << "Name: " << equipment._name << endl;
    cout << "Description: " << equipment._description << endl;
    cout << "Type: " << equipment._type << endl;
    cout << "Effect Value: " << equipment._effect_value << endl;
    cout << "Element: " << equipment._element << endl;
    cout << "Price: " << equipment._price << endl;
}

Equipment Entity::getEquippedWeapon() const
{
    if (!_equipped.empty())
    {
        // Assume the first item is the weapon
        return _equipped[0];
    }
    else
    {
        return Equipment();
    }
}

double Entity::getEquippedWeaponDamage() const
{
    if (_equipped.empty())
    {
        return 0.0; // No weapon equipped
    }

    // Get the equipped weapon's damage
    double weapon_damage = _equipped[0]._effect_value;
    // randomize damage using rand
    double random_damage = (rand() % static_cast<int>(weapon_damage) + 1);
    return random_damage;
}

void Entity::addToInventory(Equipment item)
{
    _inventory.push_back(item);
}
