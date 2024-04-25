// CSCI 1300 Spring 2024
// Author: Lucas Garcia
// TA: Elsie Tate
// Entity.cpp

#include <iostream>
#include "Entity.h"
using namespace std;

// Default constructor
Entity::Entity()
{
    _gold = 0;                // Initialize gold
    _hp = 0;                  // Initialize HP
    _stamina = 0;             // Initialize stamina
    _name = "";               // Initialize name
    _condition = 'H';         // Initialize cond.
    _advantage = false;       // Initialize advantage
    _elementalWeakness = ' '; // Initialize elemental weakness
    _numberOfItems = 0;       // Initialize number of items
    _ultimate = "";           // Initialize ultimate
    _calamity = 0.0;          // Initialize calamity
}

// Parameterized constructor
Entity::Entity(string name, char type, double hp, double stamina, double defense, char condition,
               bool advantage, char elementalWeakness, int gold, string startingItems,
               int numberOfItems, string ultimate)
{
    _name = name;
    _type = type;
    _hp = (hp >= 0) ? hp : 0;
    _stamina = (stamina >= 0) ? stamina : 0;
    _defense = (defense >= 0) ? defense : 0;
    _condition = (condition == 'H' || condition == 'D' || condition == 'P') ? condition : 'H';
    _advantage = advantage;
    _elementalWeakness = (elementalWeakness == 'F' || elementalWeakness == 'W' || elementalWeakness == 'E' || elementalWeakness == 'A') ? elementalWeakness : 'W';
    _gold = (gold >= 0) ? gold : 0;
    _startingItems = startingItems;
    _numberOfItems = (numberOfItems >= 0) ? numberOfItems : 0;
    _ultimate = ultimate;
    _calamity = 0.0; // Initialize calamity
}

Entity::Entity(string name, string discription, char type, double effect_value, char element, double price)
{
    _name = name;
    _discription = discription;
    _type = type;
    _effect_value = effect_value;
    _element = element;
    _price = price;
}

// Getter methods
string Entity::getName()
{
    return _name;
}

double Entity::getHP()
{
    return _hp;
}

double Entity::getStamina()
{
    return _stamina;
}

double Entity::getDefense()
{
    return _defense;
}

char Entity::getCondition()
{
    return _condition;
}

bool Entity::getAdvantage()
{
    return _advantage;
}

char Entity::getElementalWeakness()
{
    return _elementalWeakness;
}

int Entity::getGold()
{
    return _gold;
}

string Entity::getStartingItems()
{
    return _startingItems;
}

int Entity::getNumberOfItems()
{
    return _numberOfItems;
}

string Entity::getUltimate()
{
    return _ultimate;
}

float Entity::getCalamity()
{
    return _calamity;
}

string Entity::getDiscription()
{
    return _discription;
}

char Entity::getType()
{
    return _type;
}

double Entity::getEffect_value()
{
    return _effect_value;
}

char Entity::getElement()
{
    return _element;
}

double Entity::getPrice()
{
    return _price;
}

// Setter methods
void Entity::setName(string name)
{
    _name = name;
}

void Entity::setHP(double hp)
{
    _hp = (hp >= 0) ? hp : 0;
}

void Entity::setStamina(double stamina)
{
    _stamina = (stamina >= 0) ? stamina : 0;
}

void Entity::setDefense(double defense)
{
    _defense = (defense >= 0) ? defense : 0;
}

void Entity::setCondition(char condition)
{
    _condition = (condition == 'H' || condition == 'D' || condition == 'P') ? condition : 'H';
}

void Entity::setAdvantage(bool advantage)
{
    _advantage = advantage;
}

void Entity::setElementalWeakness(char elementalWeakness)
{
    _elementalWeakness = elementalWeakness;
}

void Entity::setGold(int gold)
{
    _gold = (gold >= 0) ? gold : 0;
}

void Entity::setStartingItems(string startingItems)
{
    _startingItems = startingItems;
}

void Entity::setNumberOfItems(int numberOfItems)
{
    _numberOfItems = (numberOfItems >= 0) ? numberOfItems : 0;
}

void Entity::setUltimate(string ultimate)
{
    _ultimate = ultimate;
}

void Entity::setCalamity(float calamity)
{
    _calamity = calamity;
}

void Entity::printStats()
{
    cout << _name << "'s stats:" << endl;
    cout << "Type: " << _type << endl;
    cout << "HP: " << _hp << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Defense: " << _defense << endl;
    cout << "Condition: " << _condition << endl;
    cout << "Advantage: " << (_advantage ? "True" : "False") << endl;
    cout << "Elemental Weakness: " << _elementalWeakness << endl;
    cout << "Gold: " << _gold << endl;
    cout << "Starting Items: " << _startingItems << endl;
    cout << "Number of Items: " << _numberOfItems << endl;
    cout << "Ultimate: " << _ultimate << endl;
}

void Entity::printStatsItem()
{
    cout << _name << endl;
    cout << "Discription: " << _discription << endl;
    cout << "Type: " << _type << endl;
    cout << "Effect Value: " << _effect_value << endl;
    cout << "Element: " << _element << endl;
    cout << "Price: " << _price << endl;
}

void Entity::setDiscription(string discription)
{
    _discription = discription;
}

void Entity::setType(char type)
{
    _type = type;
}

void Entity::setEffect_value(double effect_value)
{
    _effect_value = effect_value;
}

void Entity::setElement(char element)
{
    _element = element;
}

void Entity::setPrice(double price)
{
    _price = price;
}

