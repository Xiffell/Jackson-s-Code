#include <iostream>
using namespace std;

#ifndef STRUCTS_H
#define STRUCTS_H

struct Potion
{
    string _potion_name;
    char _potion_type;
    double _effect_value;
    int _quantity;
};

struct Equipment
{
    string _name;
    char _equipment_type;
    char _element;
    double _damage;
    double _defence;
    double _price;
};

#endif