#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //double number = 100.0;
    //cout << fixed << setprecision(2) << number << endl;

    double x,y;
    cout << fixed << setprecision(3);

    x = 12.3761;
    y = 0.03154;

    cout << setw(8) << x << endl;
    cout << setw(8) << y << endl;

    cout << endl << setw(5) << x << endl;
    cout << setw(5) << y << endl << endl;

    cout << 7/2 << endl; // Outputs 3
    cout << 7.0/2 << endl << endl; // Outputs 3.5

    cout << +-2 << endl;
    cout << 3+-2 << endl << endl;

    cout << 'A' + 3 << endl; // Outputs 68
    cout << char('A' + 3) << endl; // Outputs D
}