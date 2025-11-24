/*
Course: CISC 1600
Name: Jan Czeladko
Date: November 10, 2025
File: HW9.cpp
Assignment: Write a program that uses functions discussed in the class (or something similar)
to populate an integer array of size 20 with random integers in range [1, 5], and outputs
the array and the average of all values in the array elements.
*/

#include <iostream>
#include <iomanip>

using namespace std;

unsigned int seed = 12345;
double random(unsigned int &seed);
int RandomInt(int low, int high);
void fill_array(int a[], int size, int low, int high);
double average_array(int a[], int size);

int main()
{
    int a[20];
    double average;

    fill_array(a, 20, 1, 5);

    cout << "Array elements: ";
    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    average = average_array(a, 20);
    cout << "Average = " << fixed << setprecision(2) << average << endl;
    
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
    for (int i = 0; i < size; i++)
    {
        a[i] = RandomInt(low, high);
    }
}

double average_array(int a[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    return double(sum) / size;
}


/*
Sample Output:
Array elements: 2 5 2 1 1 4 2 4 2 5 1 5 5 2 5 2 1 3 5 5 
Average = 3.10
*/