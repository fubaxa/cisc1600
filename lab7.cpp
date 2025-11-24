/*
Course: CISC 1610
Name: Jan Czeladko
Date: November 10, 2025
File: lab7.cpp
Assignment: Write a program that uses structure REcord which has three fields,
ch - of character type, n - of integer type, and x - of type double,
to declare an array a of size 10 of type Record, uses function fill_array to populate
all fields with ch - random small letters,  n - random integers in [5, 10], 
x - random doubles in [5.0, 10.0]. Use the function print_array to print the contents of
all fields of all records in the array.
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 10;

unsigned int seed = 12345;
double random(unsigned int &seed);
char RandomSmallLetter();
int RandomInteger(int low, int high);
double RandomDouble(double low, double high);
void fill_array(struct Record a[], int size);
void print_array(struct Record a[], int size);

struct Record
{
    char ch;
    int n;
    double x;
};

int main()
{
    Record a[SIZE];

    fill_array(a, SIZE);

    cout << "Array elements:" << endl;
    print_array(a, SIZE);

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

char RandomSmallLetter()
{
    return 'a' + int(random(seed) * 26);
}

int RandomInteger(int low, int high)
{
    return low + int(random(seed) * (high - low + 1));
}

double RandomDouble(double low, double high)
{
    return low + random(seed) * (high - low);
}

void fill_array(struct Record a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i].ch = RandomSmallLetter();
        a[i].n = RandomInteger(5, 10);
        a[i].x = RandomDouble(5.0, 10.0);
    }
}

void print_array(struct Record a[], int size)
{
    cout << left << setw(10) << "Char" << setw(10) << "Integer" << setw(10) << "Double" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(10) << a[i].ch << setw(10) << a[i].n << setw(10) << fixed << setprecision(2) << a[i].x << endl;
    }
}

/*
Sample Output:
Array elements:
Char      Integer   Double    
j         10        6.52      
d         6         8.69      
g         9         6.49      
x         5         9.69      
w         7         9.42      
i         5         7.05      
w         10        5.31      
d         5         9.09      
t         8         7.81
q         10        7.78
*/