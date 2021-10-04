#pragma once
#include <initializer_list>
#include <iostream>

using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Matrix
    {
    private:
        int size_x_, size_y_;
        T** matrix_;
    public: 

        Matrix (int size_x, int size_y, initializer_list<initializer_list<T>> matrix);
        Matrix (int size_x, int size_y, T** matrix);
        Matrix (int size_x, int size_y);
        Matrix ();
        Matrix (const Matrix &matrix1);
        ~Matrix ();

        Matrix& Tran ();
        bool is_right_step();
        //bool is_left_step();
        int get_size_x();
        int get_size_y();
        Matrix pow (int power); 
        Matrix get_identity_matrix (); 
        

        Matrix& operator= (const Matrix& matrix);

        Matrix operator+   (const Matrix& rhs);
        Matrix operator-   (const Matrix& rhs);
        Matrix operator*   (const Matrix& rhs);
        Matrix operator*=  (const Matrix& rhs);
        Matrix operator*   (const int rhs);
        T*   operator[]    (const int index);
        template <typename T> friend ostream& operator<< (ostream &out, const Matrix<T> &matrix);
        template <typename T> friend istream& operator>> (istream  &in,       Matrix<T> &matrix);

    };

#include "matrix.inl"

#endif ARRAY_H