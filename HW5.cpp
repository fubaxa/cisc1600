/*
Course: CISC 1600
Name: HW5
Date: October 13, 2025
File: HW5.cpp
Assignment: Write a program that uses function random
 introduced in class to compute the value of Pi.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

unsigned int seed;

double random(unsigned int &seed);
bool is_inside_circle(double x, double y);
double compute_pi(int total_points);

int main()
{
    int total_points = 1000000;

    cout << "Enter a non-negative seed: "; 
    cin >> seed;

    double pi = compute_pi(total_points);

    cout << fixed << setprecision(10);
    cout << "Estimated Pi = " << pi << endl;

    return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 32792;
    const int MULTIPLIER = 50349;
    const int INCREMENT = 1;

    seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;

    return double(seed) / MODULUS;
}

bool is_inside_circle(double x, double y)
{
    return (x * x + y * y) <= 1.0;
}

double compute_pi(int total_points)
{
    int points_inside_circle = 0;

    for (int i = 0; i < total_points; ++i)
    {
        double x = random(seed);
        double y = random(seed);

        if (is_inside_circle(x, y))
        {
            ++points_inside_circle;
        }
    }

    return 4.0 * points_inside_circle / total_points;
}


/*
Sample output:
Enter a non-negative seed: 2312312
Estimated Pi = 3.1478840000
*/