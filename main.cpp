#include <iostream>
#include <cstdlib> 

#include "matrix.h"

using namespace std;

int main()
    {
    Matrix test1(2, 2, {{1, 2}, {3, 4}});
    Matrix test2(2, 3, {{1, 2}, {3, 4}, {5, 6}});

    cout << test1 * test2;
    test2.Tran();
    cout << test2;

    system("pause");
    return 0;
    }