/*
Course: CISC 1600
Name: HW6
Date: October 16, 2025
File: HW6.cpp
Assignment: Write a program that accepts from the keyboard the initial 
height h of the bouncing ball and its bounciness
ratio r, and outputs the total distance 
traveled by the ball until it stops bouncing.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    double h, r;

    cout << endl;
    cout << "Enter the initial height: ";
    cin >> h;
    cout << "Enter the bounciness ratio between 0 and 1: ";
    cin >> r;
    cout << endl;

    double total_distance = 0.0;
    double current_height = h;

    if (h < 0 || r < 0 || r >= 1) 
    {
        cout << "Error: invalid input" << endl;
        return 1;
    }

    do
    {
        total_distance += current_height;
        current_height *= r;
        total_distance += current_height;
    } while (current_height > 0.0001);

	// total_distance = h + 2 * h * r / (1 - r);

    cout << fixed << setprecision(4);
    cout << "  Initial height = " << setw(10) << h << endl;
    cout << "Bounciness ratio = " << setw(10) << r << endl;
    cout << "  Total distance = " << setw(10) << total_distance << endl;
    cout << endl;

    return 0;
}

/*
Sample output 1:

Enter the initial height: 12
Enter the bounciness ratio between 0 and 1: 0.95

  Initial height =  12.0000
Bounciness ratio =   0.9500
  Total distance = 467.6252

Sample output 2:

Enter the initial height: 12
Enter the bounciness ratio between 0 and 1: 1

Error: invalid input
*/