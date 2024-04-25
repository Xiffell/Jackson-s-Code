// CSCI 1300 Spring 2024
// Author: Lucas Garcia
// TA: Elsie Tate
// Map.cpp

#include <iostream>
#include "Map.h"
using namespace std;

#define RED "\033[41m"     // Red
#define GREEN "\033[42m"   // Green
#define BLUE "\033[44m"    // Blue
#define MAGENTA "\033[45m" // Magenta
#define CYAN "\033[46m"    // Cyan
#define RESET "\033[0m"

Map::Map() {}

Map::Map(int players_num, int size)
{
    //cout << "Created a Map Array!" << endl;
    m_mapArr[players_num][size] = {};
}

// setter for position on map given the value and which player and then the index for their lane
void Map::setMapPos(string value, int playerID, int index)
{
    m_mapArr[playerID][index] = value;
}

// getter for position on map given which player and then the index for their lane
string Map::getMapPos(int playerID, int index)
{
    return m_mapArr[playerID][index];
}

void Map::initializeMap()
{

    // variables to hold random numbers
    int rand_num1, rand_num2;

    m_mapArr[0][0] = BLUE;
    m_mapArr[1][0] = BLUE;

    m_mapArr[0][49] = MAGENTA;
    m_mapArr[1][49] = MAGENTA;

    for (int i = 1; i < 49; i++)
    {
        /* generate secret number between 1 and 10: */
        rand_num1 = rand() % 10 + 1;
        rand_num2 = rand() % 10 + 1;

        // These conditions roughly set probability for red, green, and blue tiles to roughly 1/3ish
        // STUDENTS: You must alter these to get correct ratios of the tiles that you need
        // Remember, the map is ALWAYS randomized at the start of a new game!!!!
        if (rand_num1 <= 3)
        {
            // Keep in mind, I told the compiler that writing the word RED represents the string "\033[41m"
            m_mapArr[0][i] = RED;

            if (m_mapArr[0][i] == m_mapArr[0][i-1])
            {
                m_mapArr[0][i] = BLUE;
            }
        }
        else if (rand_num1 <= 6)
        {
            // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[42m"
            m_mapArr[0][i] = GREEN;

            if (m_mapArr[0][i] == m_mapArr[0][i-1])
            {
                m_mapArr[0][i] = BLUE;
            }
        }
        else
        {
            // Keep in mind, I told the compiler that writing the word BLUE represents the string "\033[44m"
            m_mapArr[0][i] = BLUE;
        }

        // This part populates the other lane for the second player
        if (rand_num2 <= 3)
        {
            m_mapArr[1][i] = RED;

            if (m_mapArr[1][i] == m_mapArr[1][i-1])
            {
                m_mapArr[1][i] = BLUE;
            }
        }
        else if (rand_num2 <= 6)
        {

            m_mapArr[1][i] = GREEN;

            if (m_mapArr[1][i] == m_mapArr[1][i-1])
            {
                m_mapArr[1][i] = BLUE;
            }
        }
        else
        {
            m_mapArr[1][i] = BLUE;
        }
    }
}

void Map::printMap()
{
    // Define the dimensions of each cell
    const int cellWidth = 1; // Adjust as needed
    const int cellHeight = 1; // Adjust as needed

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 50; ++j)
        {
            // Print the color escape sequence directly
            cout << m_mapArr[i][j];

            // Print multiple characters to create a square cell
            for (int k = 0; k < cellWidth; ++k)
            {
                for (int l = 0; l < cellHeight; ++l)
                {
                    cout << " ";
                }
                cout << " "; // Separate cells horizontally
            }

            // Check where palyers are and print P1 or P2 on that square
            
        }
        // Reset color at the end of each row
        cout << RESET << endl;
    }

    cout << endl;
}
