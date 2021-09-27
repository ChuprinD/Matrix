#pragma once
#include <initializer_list>
#include <ostream>

using namespace std;

class Matrix
    {
    public:

        int size_x_, size_y_;
        int** matrix_;

        Matrix (int size_x, int size_y, initializer_list<initializer_list<int>> matrix);
        Matrix (int size_x, int size_y, int** matrix);
        Matrix (int size_x, int size_y);
        Matrix ();
        Matrix (const Matrix &matrix1);
        ~Matrix ();

        Matrix& Tran ();
        bool is_right_step();
        //bool is_left_step();

        Matrix& operator= (const Matrix &matrix);

        friend Matrix operator+ (const Matrix &lhs, const Matrix &rhs);
        friend Matrix operator- (const Matrix &lhs, const Matrix &rhs);
        friend Matrix operator* (const Matrix &lhs, const Matrix &rhs);
        friend Matrix operator* (const Matrix &lhs, const int rhs);
        friend ostream& operator<< (ostream &out, const Matrix &matrix);


    };