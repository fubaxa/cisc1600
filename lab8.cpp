/*
Course: CISC 1610
Name: Jan Czeladko
Date: November 17, 2025
File: lab8.cpp
Assignment: Write a program that uses a recursive function "n choose k" 
for the computation of the binomial for 
which the values of n and k are entered from the keyboard.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int n_choose_k(int n, int k);
int factorial(int n);

int main()
{
    int n, k;

    cout << "Enter n and k (both larger than 0): ";
    cin >> n >> k;

    if (n < k || k < 0)
    {
        cout << "Invalid input. Ensure that n >= k >= 0." << endl;
        return 1;
    }

    int result = n_choose_k(n, k);

    cout << "C(" << n << ", " << k << ") = " << result << endl;

    return 0;
}

int n_choose_k(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return n_choose_k(n - 1, k - 1) + n_choose_k(n - 1, k);
}

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}


/*
Sample Output:
Enter n and k (both larger than 0): 8
2
C(8, 2) = 28
*/