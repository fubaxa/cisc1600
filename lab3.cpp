/*
Course: CISC 1610
Name: lab3.cpp
Date: October 6, 2025
File: lab3.cpp
Assignment: Write a program that uses the random(seed) from class 
to generate 10000 random numbers in range [0, 5], 
and outputs the average of the generate numbers
*/

#include <iostream>
#include <iomanip>

using namespace std;

unsigned int seed;
double random(unsigned int &seed);

int main()
{
    double sum = 0.0;
    const int N = 10000;

    cout << "Enter a non-negative seed: "; 
    cin >> seed;
    cout << endl;

    for (int i = 0; i < N; ++i)
    {
        double rand_num = int (random(seed) * 6);
        sum += rand_num;
    }

    double average = sum / N;

    cout << fixed << setprecision(3);
    cout << "Average = " << setw(6) << average << endl;

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
Enter a non-negative seed: 7

Average =  2.489
*/