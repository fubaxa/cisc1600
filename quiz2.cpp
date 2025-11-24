/*
Course: CISC 1600
Name: Jan Czeladko
Date: November 6, 2025
File: quiz2.cpp
Assignment: Babylonian Method for Computing the Square Root.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double babylon_sqrt(double a);

int main() 
{
    double a;

    cout << endl;
    cout << "Enter a number greater than or equal to 0: ";
    cin >> a;

    if (a < 0) 
    {
        cout << "Error: Please enter a number greater than or equal to 0." << endl;
        return 1;
    }

    cout << endl;
    cout << fixed << setprecision(10);
    cout << " babylon_sqrt(" << a << ") = " << setw(15) << babylon_sqrt(a) << endl;
    cout << "built_in_sqrt(" << a << ") = " << setw(15) << sqrt(a) << endl;
    cout << endl;

    return 0;
}

double babylon_sqrt(double a) 
{
    if (a == 0) 
    {
        return 0.0;
    }

    double x = a / 2.0;
    double new_x;
    double tolerance = 1e-10;
    double difference;

    do 
    {
        new_x = (x + a / x) / 2.0;
        difference = fabs(new_x - x);
        x = new_x;
    } while (difference >= tolerance);

    return x;
}

/*
Sample output:

Enter a number greater than or equal to 0: 50

 babylon_sqrt(50.0000000000) =    7.0710678119
built_in_sqrt(50.0000000000) =    7.0710678119

*/
