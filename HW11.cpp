/*
Course: CISC 1600
Name: Jan Czeladko
Date: November 17, 2025
File: HW11.cpp
Assignment: Write a program that uses Structure Point discussed in the class to declare an array
of 100 points (use function fill_array to do this task), and outputs the # of points
with distances between them that are greater than one. Use function greater_distance that returns that value.*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE = 100;

unsigned int seed = 12345;
double random(unsigned int &seed);
void fill_array(struct Point a[], int size);
int greater_distance(struct Point a[], int size);
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

    int count = greater_distance(a, SIZE);

    cout << "# of pairs with distance greater than 1 = " << count << endl;

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
        a[i].x = random(seed);
        a[i].y = random(seed);
    }
}

int greater_distance(struct Point a[], int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            double dist = distance(a[i], a[j]);
            if (dist > 1.0)
            {
                count++;
            }
        }
    }
    return count;
}

double distance(struct Point p1, struct Point p2)
{
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

/*
Sample output:
# of pairs with distance greater than 1 = 174
*/