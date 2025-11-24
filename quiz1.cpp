/*
Course: CISC 1600
Name: q1
Date: October 16, 2025
File: q1.cpp
Assignment: Given is the sequence of squares in which the first square has the area of 4,
and each consecutive square in the sequence has the area which is 
half of the area of the previous square in the sequence. The sum of areas 
of certain number of squares in such sequence equals 255/32. Write a program
that determines the number of squares in such sequence.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    double area = 4.0;
    double target_area = 255.0 / 32.0;
    int count = 0;
    double total_area = 0.0;

    while (total_area < target_area) 
    {
        total_area += area;
        area /= 2.0;
        count++;
    }

    cout << endl;
    cout << "Number of squares = " << setw(1) << count << endl;
    cout << endl;

    return 0;
}

/*
Sample output:

Number of squares = 8

*/