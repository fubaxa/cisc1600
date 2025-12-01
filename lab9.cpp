/*
Course: CISC 1610
Name: Jan Czeladko
Date: November 24, 2025
File: lab9.cpp
Assignment: None.
*/

#include <vector>
#include <cassert>

using namespace std;

struct Node 
{
    Node()
    {
        int_value = 0;
        double_value = 0.0;
    }

    int int_value;
    double double_value;
};

int main()
{
    vector<double> double_vec;
    vector<int> int_vec(10, 123);     
    vector<Node> node_vec(100);     

    assert(double_vec.size() == 0);
assert(int_vec.size() == 10);
assert(int_vec[0] == 123);
assert(node_vec.size() == 100);
assert(node_vec[9].int_value == 0);
assert(node_vec[9].double_value == 0.0);


    return 0;
}