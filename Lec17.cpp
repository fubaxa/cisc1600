/*
With example of array declared and populated as above write a program fragment that finds 
the location of the first occurence of value S in the array.
*/

#include <iostream>
#include <iomanip>

using namespace std;

unsigned int seed = 12345;
double random(unsigned int &seed);

const int SIZE = 10;
const int low = 5;
const int high = 10;

int S = 7;

int main() {
    int a[SIZE];

    for (int i = 0; i < SIZE; i++) {
        a[i] = int(low + (high - low + 1) * random(seed));
    }

    int i = 0;
    while (i < SIZE && a[i] != S) {
        i++;
    }

    cout << "S = " << S << " is found at index: ";
    if (i < SIZE) {
        cout << i << endl;
    } else {
        cout << "not found in the array." << endl;
    }

    cout << "Array contents: ";
    for (int j = 0; j < SIZE; j++) {
        cout << a[j] << " ";
    }
    cout << endl;

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
/*
Quiz 2 - 11/06/2025
Functions:
 - Control statements
 - Loops
*/