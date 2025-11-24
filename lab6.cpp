/*
Course: CISC 1610
Name: Jan Czeladko
Date: November 3, 2025
File: lab6.cpp
Assignment: Write a program that uses function fill_array to populate 
an integer array of size 10 with distinct random integers, each in range [10, 30].
*/

#include <iostream>
#include <iomanip>

using namespace std;

unsigned int seed = 12345;
double random(unsigned int &seed);
int RandomInt(int low, int high);
void fill_array(int a[], int size, int low, int high);

const int ARRAY_SIZE = 10;

int main()
{
    int a[ARRAY_SIZE];

    fill_array(a, ARRAY_SIZE, 10, 30);

    cout << "Array elements: ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
    return double(seed) / MODULUS;
}

int RandomInt(int low, int high)
{
    return low + int(random(seed) * (high - low + 1));
}

void fill_array(int a[], int size, int low, int high)
{
    for (int i = 0; i < size;)
    {
        int num = RandomInt(low, high);
        bool isDistinct = true;

        for (int j = 0; j < i; j++)
        {
            if (a[j] == num)
            {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct)
        {
            a[i] = num;
            i++;
        }
    }
}

/*
Sample Output:
Array elements: 17 27 16 12 13 25 15 26 28 11
*/