#include <iostream> //preprocessor directives
#include <iomanip>  //Iostream allows us to use input and output functions, Iomanip is a library that allows us to format the numbers

using namespace std;  //Used for the sake of convenience

int main(){     //program header
    int n_1, n_2, sum;  //The indentation is 3-4 spaces, it's not necessary for the program to work but it improves readability; declaration of variables
    cout << "Enter n_1: ";  //Input section
    cin >> n_1;
    cout << "Enter n_2: ";
    cin >> n_2;
    sum = n_1 + n_2;    //Computation section
    cout << "Sum = " << sum << endl;  //Output section  
    return 0;   
}