/*
Course: CISC 1600
Name: Jan Czeladko
Date: September 25, 2025
File: HW1.cpp
Assignment: Write a program that accepts three values a, b, and c from keyboard inputs and outputs the area of the triangle if a, b, c, form a triangle, 
and outputs a message like “Value a, b, c do not form a triangle.”
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() 
{
    double a, b, c, s, area;

    cout << endl << "Enter three values for the sides of a triangle: " << endl;
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0)
    {
        s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "The area of the triangle is: " << area << endl;
    } 
    else 
    {
        cout << "Values " << a << ", " << b << ", " << c << " do not form a triangle." << endl;
    }

    cout << endl;
    return 0;
}


/*
Sample output 1:

Enter three values for the sides of a triangle: 
13
6
7
Values 13, 6, 7 do not form a triangle.

Sample output 2:
Enter three values for the sides of a triangle:
3
4
5
The area of the triangle is: 6
*/