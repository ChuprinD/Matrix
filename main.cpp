#include <iostream>
#include <cstdlib> 

#include "matrix.h"

using namespace std;

int main()
    {
    Matrix<int> test1 (5, 4, {{1, 2, 4, 5, 6}, 
                              {0, 2, 4, 5, 6},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}});
    Matrix<double> test2 (2, 3, {{1.2, 2.1}, {3.5, 4.3}, {5.1, 6.0}});
    Matrix<int> test3 (3, 3, {{1, 2, 3}, {4, 7, 6}, {7, 8, 9}});
    Matrix<char> test4;

    /*cout << test1;
    cout << test3 << endl;
    cout << test2 << endl; */
    cout << test3.determinant() << endl;


    system("pause");
    return 0;
    }