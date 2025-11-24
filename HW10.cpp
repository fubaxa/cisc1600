/*
Course: CISC 1600
Name: Jan Czeladko
Date: November 10, 2025
File: HW10.cpp
Assignment: Write a program that declares a 2-dimensional character array a, of dimensions 5x10,
Populates the array with random capital letters and outputs the array in the matrix form.
Function should be used to populate the array and print it.
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 5;
const int COLS = 10;

unsigned int seed = 12345;
double random(unsigned int &seed);
char RandomCapitalLetter();
void fill_matrix(char a[][COLS], int rows, int cols);
void print_matrix(char a[][COLS], int rows, int cols);


int main()
{
    char a[ROWS][COLS];

    fill_matrix(a, ROWS, COLS);

    cout << "Matrix elements:" << endl;
    print_matrix(a, ROWS, COLS);

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

char RandomCapitalLetter()
{
    return 'A' + int(random(seed) * 26);
}

void fill_matrix(char a[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a[i][j] = RandomCapitalLetter();
        }
    }
}

void print_matrix(char a[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

/*
Sample output:

Matrix elements:
J W H D E T G U H X 
B Y W K W I C K W W 
B D B V T Q O Q Z O 
V A O D X L C P H I 
Z T I E Z Q L P B B 
*/