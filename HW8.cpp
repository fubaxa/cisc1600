/*
Course: CISC 1600
Name: Jan Czeladko
Date: November 3, 2025
File: HW8.cpp
Assignment: Write a program that generates 100 random points in 
the unit square and outputs the x and y coordinates 
of the points with the maximum distance between them.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

unsigned int seed = 54321;
double random(unsigned int &seed);
double distance(double x1, double y1, double x2, double y2);

const int NUM_POINTS = 100;

int main()
{
    double x[NUM_POINTS];
    double y[NUM_POINTS];

    for (int i = 0; i < NUM_POINTS; i++)
    {
        x[i] = random(seed);
        y[i] = random(seed);
    }

    double max_distance = 0.0;
    int point1_index = 0;
    int point2_index = 0;
    double dist = 0.0;

    for (int i = 0; i < NUM_POINTS; i++)
    {
        for (int j = i + 1; j < NUM_POINTS; j++)
        {
            dist = distance(x[i], y[i], x[j], y[j]);
            if (dist > max_distance)
            {
                max_distance = dist;
                point1_index = i;
                point2_index = j;
            }
        }
    }

    cout << fixed << setprecision(4);
    cout << "Point 1 = (" << x[point1_index] << ", " << y[point1_index] << ")" << endl;
    cout << "Point 2 = (" << x[point2_index] << ", " << y[point2_index] << ")" << endl;
    cout << "Maximum Distance = " << max_distance << endl;

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

double distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}


/*
Sample Output:
Point 1 = (0.0552, 0.0967)
Point 2 = (0.9720, 0.9453)
Maximum Distance = 1.2492
*/