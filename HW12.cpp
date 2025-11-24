/*
Course: CISC 1600
Name: Jan Czeladko
Date: November 20, 2025
File: HW12.cpp
Assignment: Write a program that initializes an array of size 100 of points and outputs
the coordinates of three points that form a triangle with a minimum area.
Use functions random, fill_array, compute_area given three points using heron's formula.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE = 100;
const double area_side = 100.0;

unsigned int seed = 12345;
double random(unsigned int &seed);
void fill_array(struct Point a[], int size);
double compute_area(struct Point p1, struct Point p2, struct Point p3);
double distance(struct Point p1, struct Point p2);

struct Point
{
    double x;
    double y;
};

int main()
{
    Point a[SIZE];

    fill_array(a, SIZE);

    double min_area = compute_area(a[0], a[1], a[2]);
    Point p1_min = a[0];
    Point p2_min = a[1];
    Point p3_min = a[2];

    for (int i = 0; i < SIZE - 2; i++)
    {
        for (int j = i + 1; j < SIZE - 1; j++)
        {
            for (int k = j + 1; k < SIZE; k++)
            {
                double area = compute_area(a[i], a[j], a[k]);
                if (area < min_area)
                {
                    min_area = area;
                    p1_min = a[i];
                    p2_min = a[j];
                    p3_min = a[k];
                }
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "Smallest triangle:" << endl;
    cout << "Point 1 = (" << p1_min.x << ", " << p1_min.y << ")" << endl;
    cout << "Point 2 = (" << p2_min.x << ", " << p2_min.y << ")" << endl;
    cout << "Point 3 = (" << p3_min.x << ", " << p3_min.y << ")" << endl;
    cout << fixed << setprecision(10);
    cout << "Minimum Area = " << min_area << endl;

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

void fill_array(struct Point a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i].x = random(seed)*area_side;
        a[i].y = random(seed)*area_side;
    }
}

double compute_area(struct Point p1, struct Point p2, struct Point p3)
{
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double distance(struct Point p1, struct Point p2)
{
    double x = p2.x - p1.x;
    double y = p2.y - p1.y;
    return sqrt(x * x + y * y);
}

/*
Sample Output:
Smallest triangle:
Point 1 = (92.81, 48.75)
Point 2 = (94.64, 54.37)
Point 3 = (88.55, 35.64)
Minimum Area = 0.0000000000
*/