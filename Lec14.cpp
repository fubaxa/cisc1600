#include <iostream>
#include <iomanip>

using namespace std;

unsigned int seed = 58688;
double random(unsigned int &seed);

char random_char();

int main()
{
    while (true)
    {
        char c = random_char();
        cout << "Random character: " << c << endl;
        if (c == 'z')
        {
            break;
        }
    }
    return 0;
}

char random_char()
{
    const char CHAR_START = 'a';
    const char CHAR_END = 'z';
    int range = CHAR_END - CHAR_START + 1;
    int random_index = int(random(seed) * range);
    return CHAR_START + random_index;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
    return double(seed) / MODULUS;
}