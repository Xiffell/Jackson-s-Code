#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Potion
{
    string name;
    char type;
    double effect_value;
    int quantity;
};

struct Equipment
{
    string name;
    char type;
    char element;
    double damage;
    double defense;
    double price;
    Equipment() : name(""), type('\0'), element('\0'), damage(0.0), defense(0.0), price(0.0) {}
};

class Entity
{
public:
    // Constructor
    Entity();

    // setters and getters
    void setName(string);
    void setHP(double);
    void setStamina(double);
    void setDefence(double);
    void setCondition(char);
    void setAdvantage(bool);
    void setGold(int);

    string getName() const;
    double getHP() const;
    double getStamina() const;
    double getDefense() const;
    char getCondition() const;
    bool getAdvantage() const;
    int getGold() const;

    Equipment getEquippedWeapon() const;
    double getEquippedWeaponDamage() const;
    bool isEquippedEmpty() const { return _equipped.empty(); }

    // fucntion to swap what the player has equipped
    void swap(int userChoice);
    // function to drop weapons or items
    void drop(int userChoice);
    void usePotion(int userChoice);
    void updateEquipment(int equipIndex, Equipment weapon);
    void printEntityStats(Entity entity);

private:
    string _name;
    double _HP;
    double _stamina;
    double _defense;
    char _condition;
    bool _advantage;
    int _gold;
    // vector of all potions that are currently held by the player (max 3 slots for 3 stacks of potions)
    vector<Potion> _potions;
    // vector of all equiped equipment(max 2 pieces(w,w||w,s))
    vector<Equipment> _equipped;
    // vector of all things the player owns but does not have equipped
    vector<Equipment> _inventory;
    // vector that holds two integers (1-total stock of potions, 2- total stock of equipment)
    vector<int> _items;
    // probability of calamity
    float _calamity;
};

#endif