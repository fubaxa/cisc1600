/*
Course: CISC 1610
Name: Jan Czeladko
Date: October 27, 2025
File: lab5.cpp
Assignment: Write a program that declares an integer array a of size 50, 
populates the array with random integers, each in range [3, 7], 
and outputs all positions at which the array element is 4.
*/

#include <iostream>
#include <iomanip>

using namespace std;

unsigned int seed = 2025;
double random(unsigned int &seed);

const int SIZE = 50;
const int LOW = 3;
const int HIGH = 7;

const int S = 4;

int main()
{
    int a[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        a[i] = LOW + int((HIGH - LOW + 1) * random(seed));
    }

    cout << "Indexes of value 4 in the array:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (a[i] == S)
        {
            cout << i << " ";
        }
    }

    cout << endl << endl << "Array contents:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
    return double(seed) / MODULUS;
}


/*
Sample Output:
Indexes of value 4 in the array:
2 4 9 13 14 16 18 21 24 25 27 37 39 40 45 49

Array contents:
7 6 4 6 4 3 6 5 3 4
6 5 5 4 4 3 4 3 4 5
5 4 7 5 4 4 3 4 3 7
5 3 3 3 5 5 5 4 3 4
4 3 6 7 5 4 6 3 7 4
*/


