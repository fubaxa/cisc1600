/*
Course: CISC 1600
Name: Jan Czeladko
Date: October 6, 2025
File: HW4.cpp
Assignment: Write a program that enters from the keyboard
three sides of a the triangle a, b, c, 
and must output the area of the triangle computed using the Heron's formula.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double area(double a, double b, double c);

int main() 
{
    double a, b, c;
    cout << "Enter the three sides of the triangle: ";
    cin >> a >> b >> c;
     
    cout << endl;
    
    if (a + b <= c || a + c <= b || b + c <= a || a <= 0 || b <= 0 || c <= 0) {
        cout << "Values " << a << ", " << b << ", " << c << " do not form a triangle." << endl;
        return 0;
    }

    double triangle_area = area(a, b, c);

    cout << fixed << setprecision(2);
    cout << "   a = " << setw(6) << a << endl;
    cout << "   b = " << setw(6) << b << endl;
    cout << "   c = " << setw(6) << c << endl;
    cout << "Area = " << setw(6) << triangle_area << endl;

    return 0;
}

double area(double a, double b, double c) 
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

/*
Sameple output 1:
Enter the three sides of the triangle: 3
4
5

   a =   3.00
   b =   4.00
   c =   5.00
Area =   6.00

Sample output 2:
Enter the three sides of the triangle: 1
2
3

Values 1, 2, 3 do not form a triangle.
*/