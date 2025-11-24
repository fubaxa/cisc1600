#include <iostream>

using namespace std;

int cube(int n);

int main()
{
    int number;
    cout << "Enter an integer: " << endl;
    cin >> number;
    cout << "The cube of " << number;
    cout << " is " << cube(number) << endl;
    return 0;
}

int cube(int n)
{
    return n * n * n;
}