/*
Course: CISC 1600
Name: Jan Czeladko
Date: October 27, 2025
File: HW7.cpp
Assignment: As described in the race.pdf file.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

unsigned int seed = 12345;
double random(unsigned int &seed);

double time_taken(double x, double y, double z);

int main()
{
    const double total_distance = 15.0;
    double x, y, z, f1, f2, f3, t_new;
    double t = 200.0;

    cout << fixed << setprecision(3);

    for (int i = 0; i < 100000; i++)
    {
        f1 = random(seed);
        f2 = random(seed);
        f3 = random(seed);

        x = total_distance * f1 / (f1 + f2 + f3);
        y = total_distance * f2 / (f1 + f2 + f3);
        z = total_distance * f3 / (f1 + f2 + f3);

        t_new = time_taken(x, y, z);
        if (t_new < t){
            t = t_new;

            cout << endl;
            cout << "x = " << setw(6) << x << " miles" << endl;
            cout << "y = " << setw(6) << y << " miles" << endl;
            cout << "z = " << setw(6) << z << " miles" << endl;
            cout << "t = " << setw(6) << t << " hours" << endl;
        }
    }
    return 0;
}

double time_taken(double x, double y, double z)
{
    return sqrt(8*8 + x*x) / 3 + y / 5.0 + sqrt(6*6 + z*z) / 4.0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
    return double(seed) / MODULUS;
}

/*
Sample output:

x =  3.706 miles
y =  8.320 miles
z =  2.974 miles
t =  6.277 hours

x =  1.963 miles
y =  2.661 miles
z = 10.376 miles
t =  6.275 hours

x =  7.029 miles
y =  0.586 miles
z =  7.384 miles
t =  6.046 hours

x =  5.839 miles
y =  1.933 miles
z =  7.229 miles
t =  6.036 hours

x =  5.957 miles
y =  1.270 miles
z =  7.774 miles
t =  6.034 hours

x =  5.946 miles
y =  1.038 miles
z =  8.016 miles
t =  6.033 hours

x =  6.021 miles
y =  0.969 miles
z =  8.011 miles
t =  6.033 hours


Optimal solution:

x =  6.000 miles
y =  1.000 miles
z =  8.000 miles
t =  6.033 hours
*/