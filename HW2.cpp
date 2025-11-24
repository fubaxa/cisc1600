/*
Course: CISC 1600
Name: Jan Czeladko
Date: September 28, 2025
File: HW2.cpp
Assignment: Write a program that accepts from the keyboard coefficients a, b, and c of the quadriatic equation 
and displays the real roots of the equation and never fails
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, x1, x2, delta, sign_b;

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

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Infinite number of solutions." << endl;
            }
            else
            {
                cout << "No solution." << endl;
            }
        }
        else
        {
            x1 = -c / b;
            cout << "Linear equation. x = " << setw(6) << x1 << endl;
        }
        return 0;
    }

    delta = b * b - 4 * a * c;

    sign_b = b/abs(b);

    cout << endl;
    cout << "Delta = " << setw(6) << delta << endl;
    cout << endl;

    if (delta < 0)
    {
        cout << "No real roots." << endl;
    }
    else if (delta == 0)
    {
        if (b == 0)
        {
            cout << "Delta equal to zero. x1 = x2 = 0" << endl;
        }
        else
        {
            x1 = -b / (2 * a);
            cout << "Delta equal to zero. x1 = x2 = " << setw(6) << x1 << endl;
        }
    }
    else
    {
        if (b*b > 10*4*a*c)
        {
            x1 = (-b + sign_b*sqrt(delta)) / (2 * a);
            x2 = c / (a * x1);
        }
        else
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
        }
        cout << "x1 = " << setw(6) << x1 << endl;
        cout << "x2 = " << setw(6) << x2 << endl;
    }

    return 0;
}

/*
Sample output 1:
    
    Enter coefficient a: 1
    Enter coefficient b: -6
    Enter coefficient c: -7

     a =  1.000
     b = -6.000
     c = -7.000

    x1 =  7.000
    x2 = -1.000

Sample output 2:

    Enter coefficient a: 1
    Enter coefficient b: -6
    Enter coefficient c: 9

     a =  1.000
     b = -6.000
     c =  9.000

    Delta equal to zero. x1 = x2 =  3.000

Sample output 3:
        
    Enter coefficient a: 0.5 
    Enter coefficient b: 1300
    Enter coefficient c: -6

    a =  0.500
    b = 1300.000
    c = -6.000


    Delta = 1690012.000

    x1 =  0.005
    x2 = -2600.005
*/