#include <iostream>

using namespace std;
unsigned int seed = 7;
double random(unsigned int &seed);

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << random(seed) << " ";
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
