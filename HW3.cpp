/*
Course: CISC 1600
Name: Jan Czeladko
Date: October 2, 2025
File: HW3.cpp
Assignment: Write a program that accepts from the keyboard an integer 1 <= n <= 5,
and outputs the sum of the series 1 + 1/2 + 1/3 + ... + 1/n
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    double sum = 0.0;

    cout << "Enter an integer from 1 to 5: ";
    cin >> n;

    cout << endl;
    cout << "  n = " << setw(1) << n << endl;

    if (n < 1 || n > 5)
    {
        cout << "Input must be between 1 and 5." << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        sum += 1.0 / i;
    }

    cout << fixed << setprecision(2);
    cout << "Sum = " << setw(3) << sum << endl;

    return 0;
}

/*
Sample Output 1:
Enter an integer from 1 to 5: 3

  n = 3
Sum = 1.83

Sample Output 2:
Enter an integer from 1 to 5: 6

  n = 6
Input must be between 1 and 5.
*/