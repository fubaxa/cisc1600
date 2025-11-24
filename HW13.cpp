/*
Course: CISC 1600
Name: Jan Czeladko
Date: November 23, 2025
File: HW12.cpp
Assignment: Write a program that uses function fib(i) that computes the n-th fibonacci #. 
Use that function to obtain a table of fibonacci #'s 
obtained by using a racursive equation as well as the function fib(i).
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_N = 30;

int f(int n);
int fib(int n);
void print_fib_table(int n);

int main()
{
    print_fib_table(MAX_N);
    return 0;
}

int f(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return f(n - 1) + f(n - 2);
}

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

void print_fib_table(int n)
{
    cout << setw(5) << "n" << setw(15) << "f(n)" << setw(15) << "fib(n)" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << setw(5) << i << setw(15) << f(i) << setw(15) << fib(i) << endl;
    }
}