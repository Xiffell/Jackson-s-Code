#include <iostream>
#include "Entity.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

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
    Potion usedPotion = _potions[userChoice];

    // Display information about the used potion
    cout << "Using potion: " << usedPotion.name << endl;

    // Apply effects based on the potion type
    switch (usedPotion.type)
    {
    case 'H': // Health potion
        _HP += usedPotion.effect_value;
        cout << "Health increased by " << usedPotion.effect_value << endl;
        break;
    case 'S': // Stamina potion
        _stamina += usedPotion.effect_value;
        cout << "Stamina increased by " << usedPotion.effect_value << endl;
        break;
    case 'D': // Defense potion
        _defense += usedPotion.effect_value;
        cout << "Defense increased by " << usedPotion.effect_value << endl;
        break;
    case 'A':
        _advantage += usedPotion.effect_value;
    default:
        cout << "Unknown potion type!" << endl;
        break;
    }

    // Delete the used potion from the _potions vector
    _potions.erase(_potions.begin() + userChoice);
}
void Entity::updateEquipment(int equipIndex, Equipment weapon)
{
    /*
    create functions that search through vector and remove that piece from palyer inventory
    */
}

void Entity::printEntityStats(Entity entity)
{
    cout << "Player :" << entity.getName() << endl;
    cout << "HP :" << entity.getHP() << endl;
    cout << "Stamina :" << entity.getStamina() << endl;
    cout << "Defense :" << entity.getDefense() << endl;
    cout << "Condition :" << entity.getCondition() << endl;
    cout << "Gold Held :" << entity.getGold() << endl;
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
    double weapon_damage = _equipped[0].damage;
    //randomize damage using rand
    double random_damage = (rand() % static_cast<int>(weapon_damage) + 1);
    return random_damage;
}