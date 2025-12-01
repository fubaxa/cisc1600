/*
Course: CISC 1610
Name: Jan Czeladko
Date: December 1, 2025
File: lab10.cpp
Assignment: Write a program that initializes a double vector 
of size 6 with random #s in range [1.0, 5.0), 
and prints the content of the vector forwards and backwards.
Use functions to fill the vector and to print its values.
Your program must have only one print function to print a vector.
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int VECTOR_SIZE = 6;
const double MIN_VALUE = 1.0;
const double MAX_VALUE = 5.0;

unsigned int seed = 12345;
double random(unsigned int &seed);
double random_double();
void fill_vector(vector<double>& vec);
void print_vector(const vector<double>& vec);

int main()
{
    vector<double> double_vec(VECTOR_SIZE);

    fill_vector(double_vec);
    print_vector(double_vec);

    return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
    return double(seed) / MODULUS;
}

double random_double()
{
    return MIN_VALUE + (MAX_VALUE - MIN_VALUE) * random(seed);
}

void fill_vector(vector<double>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        vec[i] = random_double();
    }
}

void print_vector(const vector<double>& vec)
{
    cout << fixed << setprecision(2);
    cout << "Vector contents forwards:" << endl;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "Vector contents backwards:" << endl;
    for (size_t i = vec.size(); i-- > 0; )
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

/*
Sample Output:
Vector contents forwards:
2.51 4.39 2.21 1.56 1.76 3.95
Vector contents backwards:
3.95 1.76 1.56 2.21 4.39 2.51
*/