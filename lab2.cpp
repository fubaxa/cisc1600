/*
Course: CISC 1610
Name: lab2.cpp
Date: September 29, 2025
File: lab2.cpp
Assignment: Write a program that accepts integers from the keyboard 
until the integer divisible by 2 and 3 is entered, 
and outputs the number of integers entered.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int number;
    int count = 0;

    while (true)
    {
        cout << "Enter an integer: ";
        cin >> number;
        count++;
        if (number % 2 == 0 && number % 3 == 0)
        {
            break;
        }
    }

    cout << endl;
    

    cout << " Count = " << setw(5) << count << endl;
    cout << "Number = " << setw(5) << number << endl;

    return 0;
}
