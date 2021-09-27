#include <iostream>
#include <cstdlib> 

#include "matrix.h"

using namespace std;

int main()
    {
    Matrix test1(5, 4, {{1, 2, 4, 5, 6}, 
                        {0, 2, 4, 5, 6},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}});
    Matrix test2(2, 3, {{1, 2}, {3, 4}, {5, 6}});

    cout << test1.is_right_step() << endl;

    system("pause");
    return 0;
    }