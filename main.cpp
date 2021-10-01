#include <iostream>
#include <cstdlib> 

#include "matrix.h"

using namespace std;

int main()
    {
    Matrix<int> test1(5, 4, {{1, 2, 4, 5, 6}, 
                        {0, 2, 4, 5, 6},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}});
    Matrix<double> test2(2, 3, {{1.2, 2.1}, {3.5, 4.3}, {5.1, 6.0}});
    Matrix<char> test3;
    Matrix<char> test4;

    cout << test3 + test4;
    cout << test3 << endl;
    cout << test2 << endl;
    //cout << test3[1][0] << endl;


    system("pause");
    return 0;
    }