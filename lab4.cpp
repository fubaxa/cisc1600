/*
Course: CISC 1610
Name: lab4.cpp
Date: October 20, 2025
File: lab4.cpp
Assignment: Write a program that uses function random(seed) discussed in the class 
to design function random_int that can generate random integers, each in range [5, 10], 
and outputs the # of random integers generated (by using function random_int), 
to obtain 7 random integers having the value of 6.
*/

#include <iostream>
#include <iomanip>

using namespace std;

unsigned int seed = 101;
double random(unsigned int &seed);

int main()
{
    int count = 0;
    int num_generated = 0;
    int random_int;
    const int TARGET = 7;
    const int DESIRED_VALUE = 6;

    while (count < TARGET)
    {
        random_int = 5 + random(seed) * 6;
        num_generated++;

        if (random_int == DESIRED_VALUE)
        {
            count++;
        }
    }

    cout << endl;
    cout << "Integers generated = " << setw(3) << num_generated << endl;
    cout << "     Amount of 6's = " << setw(3) << count << endl;

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

/*
Sample output:

Integers generated =  25
     Amount of 6's =   7

*/