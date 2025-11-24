/*
Course: CISC 1610
Name: Jan Czeladko
Date: September 22, 2025
File: lab1.cpp
Assignment: Write a program that accepts from the keyboard coefficients a, b, and c of the quadriatic equation and displays the real roots of the equation
*/



#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, x1, x2, delta;

    cout << endl;
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;
    cout << endl;

    cout << fixed << setprecision(3);

    cout << " a = " << setw(6) << a << endl;
    cout << " b = " << setw(6) << b << endl;
    cout << " c = " << setw(6) << c << endl;
    cout << endl;

    delta = b * b - 4 * a * c;

    //b^2 > 10*4ac

    if (delta < 0)
    {
        cout << "No real roots." << endl;
    }
    else if (delta == 0)
    {
        cout << "Delta equal to zero. One real root." << endl;
    }
    else
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        cout << "x1 = " << setw(6) << x1 << endl;
        cout << "x2 = " << setw(6) << x2 << endl;
    }

    return 0;
}

/*
Sample output:
    
    Enter coefficient a: 1
    Enter coefficient b: -6
    Enter coefficient c: -7

     a =  1.000
     b = -6.000
     c = -7.000

    x1 =  7.000
    x2 = -1.000
    
*/