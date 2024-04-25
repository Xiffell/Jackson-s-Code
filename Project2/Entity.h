// CSCI 1300 Spring 2024
// Author: Lucas Garcia
// TA: Elsie Tate
// Entity.h

#ifndef Entity_H
#define Entity_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Structs.h"
using namespace std;

class Entity {
private:

    // Player and enemy stats
    string _name;
    char _type;
    double _hp;
    double _stamina;
    double _defense;
    char _condition;
    bool _advantage;
    char _elementalWeakness;
    int _gold;
    string _startingItems;
    int _numberOfItems;
    string _ultimate;
    float _calamity;

    // Item stats
    string _discription;
    char _type;
    double _effect_value;
    char _element;
    double _price;

public:
    // Constructors
    Entity();

    // Charator/enemy
    Entity(string name, char type, double hp, double stamina, double defense, char condition,
           bool advantage, char elementalWeakness, int gold, string startingItems, int numberOfItems, string ultimate);

    // Items
    Entity(string name, string discription, char type, double effect_value, char element, double price);

    // Getter methods
    string getName();
    double getHP();
    double getStamina();
    double getDefense();
    char getCondition();
    bool getAdvantage();
    char getElementalWeakness();
    int getGold();
    string getStartingItems();
    int getNumberOfItems();
    string getUltimate();
    float getCalamity();

    string getDiscription();
    char getType();
    double getEffect_value();
    char getElement();
    double getPrice();

    // Setter methods
    void setName(string name);
    void setHP(double hp);
    void setStamina(double stamina);
    void setDefense(double defense);
    void setCondition(char condition);
    void setAdvantage(bool advantage);
    void setElementalWeakness(char elementalWeakness);
    void setGold(int gold);
    void setStartingItems(string startingItems);
    void setNumberOfItems(int numberOfItems);
    void setUltimate(string ultimate);
    void setCalamity(float calamity);

    void setDiscription(string discription);
    void setType(char type);
    void setEffect_value(double effect_value);
    void setElement(char element);
    void setPrice(double price);

    // Other methods
    void printStats();
    void printStatsItem();
    void swap(int userChoice);
    void drop(int userChoice);
    void usePotion(int userChoice);
    void updateEquipment(int equipindex, Equipment weapon);

    // Method to load data from file
    //static vector<Entity> loadEntitiesFromFile(const string& filename);
};

#endif