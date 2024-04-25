#include "Map.h"

#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

Map::Map() {}

Map::Map(int players_num, int size)
{
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
    bool flag = false;
    while (flag == false)
    {
        int rand_num1, rand_num2;
        const int MAP_SIZE = 50;
        for (int i = 0; i < MAP_SIZE; i++)
        {
            /* generate secret number between 1 and 20: */
            rand_num1 = (rand() % 20) + 1;
            rand_num2 = (rand() % 20) + 1;

            // These conditions roughly set probability for red, green, and blue tiles to roughly 1/3ish
            if (rand_num1 <= 5)
            {
                // Keep in mind, I told the compiler that writing the word RED represents the string "\033[41m"
                m_mapArr[0][i] = RED;
                if (m_mapArr[0][i - 1] == m_mapArr[0][i])
                {
                    if (rand_num1 <= 3)
                    {
                        m_mapArr[0][i] = BLUE;
                    }
                    else
                    {
                        m_mapArr[0][i] = GREEN;
                    }
                }
            }
            else if (rand_num1 <= 10)
            {
                // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[42m"
                m_mapArr[0][i] = GREEN;
                if (m_mapArr[0][i - 1] == m_mapArr[0][i])
                {
                    if (rand_num1 <= 15)
                    {
                        m_mapArr[0][i] = BLUE;
                    }
                    else
                    {
                        m_mapArr[0][i] = RED;
                    }
                }
            }
            else
            {
                // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[44m"
                m_mapArr[0][i] = BLUE;
            }

            // This part populates the other lane for the second player
            if (rand_num2 <= 5)
            {
                m_mapArr[1][i] = RED;
                if (m_mapArr[1][i - 1] == m_mapArr[1][i])
                {
                    if (rand_num2 <= 3)
                    {
                        m_mapArr[1][i] = BLUE;
                    }
                    else
                    {
                        m_mapArr[1][i] = GREEN;
                    }
                }
            }
            else if (rand_num2 <= 10)
            {

                m_mapArr[1][i] = GREEN;
                if (m_mapArr[1][i - 1] == m_mapArr[1][i])
                {
                    if (rand_num2 <= 15)
                    {
                        m_mapArr[1][i] = BLUE;
                    }
                    else
                    {
                        m_mapArr[1][i] = RED;
                    }
                }
            }
            else
            {
                m_mapArr[1][i] = BLUE;
            }
        }
        int lane_one_red_count;
        int lane_one_green_count;
        int lane_two_red_count;
        int lane_two_green_count;
        for (int i = 0; i < MAP_SIZE; i++)
        {
            if (m_mapArr[0][i] == RED)
            {
                lane_one_red_count++;
            }
            else if (m_mapArr[0][i] == GREEN)
            {
                lane_one_green_count++;
            }
            if (m_mapArr[1][i] == RED)
            {
                lane_two_red_count++;
            }
            else if (m_mapArr[1][i] == GREEN)
            {
                lane_two_green_count++;
            }
        }
        if ((lane_one_red_count >= 4) || (lane_one_green_count >= 4) || (lane_two_red_count >= 4) || (lane_two_green_count >= 4))
        {
            flag = true;
        }
    }
}

// add a asecond funciton that loops through the array to check if it has teh minimum requirements and if it doesnt have it rerun the function
// have a while loop wioth a bool variable that will set to true if the correct amount of green and red are on the squares
// then cout function and steal it from the previous function
