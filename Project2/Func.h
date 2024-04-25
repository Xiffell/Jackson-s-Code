#include <iostream>
using namespace std;

#ifndef FUNC_H
#define FUNC_H

#define RED "\033[41m"     // Red
#define GREEN "\033[42m"   // Green
#define BLUE "\033[44m"    // Blue
#define MAGENTA "\033[45m" // Magenta
#define CYAN "\033[46m"    // Cyan
#define RESET "\033[0m"

bool validateInt(string number)
{
    int length = number.length();

    if (length == 0)
    {
        return false;
    }
    else if (length == 1 && !isdigit(number[0]))
    {
        return false;
    }
    else if (number[0] == '-' || isdigit(number[0]))
    {
        for (int i = 1; i < length; i++)
        {
            if (!isdigit(number[i]))
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool validateDouble(string number)
{
    int length = number.length();

    if (length == 0)
    {
        return false;
    }
    else if (length == 1 && !isdigit(number[0]))
    {
        return false;
    }
    else if (number[0] == '-' || isdigit(number[0]) || number[0] == '.')
    {
        for (int i = 1; i < length; i++)
        {
            if (isdigit(number[i]) || number[i] == '.')
            {
                return true;
            }
        }

        return false;
    }
    else
    {
        return false;
    }
}

int split(string input_string, char seperator, string arr[], const int ARR_SIZE)
{ 
    int Ls = input_string.length();
    int count = 0;
    string segment;

    if (Ls == 0)
    {
        return 0;
    }

    for (int i = 0; i < Ls; i++)
    {
        if (input_string[i] == seperator)
        {
            if (count < ARR_SIZE)
            {
                arr[count] = segment;
                count++;
                segment = "";
            }
            else
            {
                return -1;
            }
        }
        else
        {
            segment += input_string[i];
        }
    }

    if (count < ARR_SIZE)
    {
        arr[count] = segment;
        count++;
    }
    else
    {
        return -1;
    }

    return count;
}

bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    string line;
    getline(file, line); // Skip headers
    int index = 0;

    while (getline(file, line) && index < CHARACTERS_SIZE) {
        const int MAX_STATS = 12; // Maximum number of stats in each line
        string stats[MAX_STATS];
        int statCount = split(line, '|', stats, MAX_STATS);

        if (statCount == 12) 
        { 
            string name = stats[0];
            char type = stats[1][0];
            double hp = stod(stats[2]);
            double stamina = stod(stats[3]);
            double defense = stod(stats[4]);
            char condition = stats[5][0];
            bool advantage = (stats[6] == "True");
            char elementalWeakness = stats[7][0];
            int gold = stoi(stats[8]);
            string startingItems = stats[9];
            int numberOfItems = stoi(stats[10]);
            string ultimate = stats[11];

            // Create Entity object and add it to the array
            characters[index] = Entity(name, type, hp, stamina, defense, condition, advantage, elementalWeakness, gold, startingItems, numberOfItems, ultimate);
            index++;
        } else {
            cout << "Invalid data format in file: " << filename << endl;
            return false;
        }
    }

    file.close();
    return true;
}

bool loadItems(string filename, Entity items[], const int MAX_ITEMS)
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    getline(file, line); // Skip headers

    int numItems = 0; // Initialize the number of items loaded
    while (getline(file, line) && numItems < MAX_ITEMS) 
    {
        const int ARR_SIZE = 6; // Number of fields in each line
        string arr[ARR_SIZE];

        int count = split(line, '|', arr, ARR_SIZE);
        if (count != ARR_SIZE) 
        {
            // Invalid line format
            continue;
        }

        // Extract data from array
        string name = arr[0];
        string discription = arr[1];
        char type = arr[2][0];
        double effect_value = stod(arr[3]);
        char element = arr[4][0];
        double price = stod(arr[5]);

        // Create new Entity object and store it in the items array
        items[numItems] = Entity(name, discription, type, effect_value, element, price);
        numItems++;
    }

    file.close();
    return true;
}

void printTitle(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

#endif