/*
Course: CISC 1600
Name: Jan Czeladko
Date: November 20, 2025
File: quiz3.cpp
Assignment: Creating and printing a symmetric matrix.
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int rows = 8;
const int cols = 8;
const int high = 20;
const int low = 10;

unsigned int seed = 5;
double random(unsigned int &seed);
double random_int(int low, int high);
void fill_array(int a[][cols], int rows, int cols);
void print_array(int a[][cols], int rows, int cols);

int main()
{
    int a[rows][cols];

    fill_array(a, rows, cols);

    cout << "  Generated symmetric array" << endl;
    print_array(a, rows, cols);

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

double random_int(int low, int high)
{
    return low + int(random(seed) * (high - low + 1));
}

void fill_array(int a[][cols], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < cols; j++)
        {
            a[i][j] = random_int(low, high);
            a[j][i] = a[i][j];
        }
    }
}

void print_array(int a[][cols], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

/*
Sample output:

  Generated symmetric array
  14  19  13  11  12  18  12  18
  19  13  19  10  20  19  14  19
  13  19  13  11  14  19  19  10
  11  10  11  11  10  18  18  17
  12  20  14  10  16  17  20  16
  18  19  19  18  17  18  10  16
  12  14  19  18  20  10  11  19
  18  19  10  17  16  16  19  14
*/