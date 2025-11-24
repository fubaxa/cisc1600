#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double base, height, area;

    cout << endl;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the height: ";
    cin >> height;
    cout << endl;

    cout << fixed << setprecision(4);
    cout << "  Base = " << setw(8) << base << endl;
    cout << "Height = " << setw(8) << height << endl;

    area = 0.5 * base * height;

    cout << "  Area = " << setw(8) << area << endl;
    cout << endl;

    return 0;
}