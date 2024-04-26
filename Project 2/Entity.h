#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>

using namespace std;

struct Equipment
{
    string _name;
    string _description;
    char _type;
    double _effect_value;
    char _element;
    double _price;
    Equipment();
    Equipment(string, string, char, double, char, double);
};

class Entity
{
public:
    // Constructor
    Entity();
    Entity (string name, string , double hp, double stamina, double defense, char condition, bool advantage, string elemental_weakness, int gold, vector<string> starting_items, vector<int> num_items,  string ultimate);
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
    



    string getUltimate() const;
    void setUltimate(string);

    const vector<string>&  getStartingItems() const;
    void setStartingItems(vector<string>);

    const vector<int>&  getNumItems() const;
    void setNumItems(vector<int>);

    string getElementalWeakness() const;
    void setElementalWeakness(string);

    Equipment getEquippedWeapon() const;
    double getEquippedWeaponDamage() const;
    bool isEquippedEmpty() const { return _equipped.empty(); }

    // fucntion to swap what the player has equipped
    void swap(int userChoice);
    // function to drop weapons or items
    void drop(int userChoice);
    void usePotion(int userChoice);
    void printEntityStats(Entity entity) const;
    void addToInventory(Equipment);

    int getInventorySize() const;
    Equipment getInventoryItem(int);

private:
    string _name;
    double _HP;
    double _stamina;
    double _defense;
    char _condition;
    bool _advantage;
    int _gold;
    string _elemental_weakness;
    vector<string> _starting_items;
    vector<int> _num_items;
    string _ultimate;

    // vector of all potions that are currently held by the player (max 3 slots for 3 stacks of potions)
    vector<Equipment> _entity_potions;
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
