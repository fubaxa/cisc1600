/*
Course: CISC 1600
Name: Jan Czeladko
Date: December 11, 2024
File: HW14.cpp
Assignment: Problem of Collatz
C[1] = n
C[n] = C[n / 2] - if n is even
C[n] = 3n + 1   - if n is odd
Write a C++ program that uses function collatz that computes a sequence of #s 
which starts at c[1] = n and consecutive integers in the sequence are obtained 
according to the formula given. 
The output of your program should be the sequence of the #s generated (optional) 
and the # of sequences that end with the value 1.
Your program must not use a counter variable.
*/

#include <iostream>

using namespace std;

int collatz(int n);
int countSequences(int n);

int main()
{
    int n;

    cout << "Enter how many sequences to generate: ";
    cin >> n;

    int count = countSequences(n);

    cout << endl << "The number of sequences ending with 1 = " << count << endl;
    
    return 0;
}

int collatz(int n)
{
    // cout << n << " ";

    if (n == 1)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return collatz(n / 2);
    }
    else
    {
        return collatz(3 * n + 1);
    }
}

int countSequences(int n) 
{
    if (n == 0) return 0;
    return collatz(n) + countSequences(n - 1);
}

