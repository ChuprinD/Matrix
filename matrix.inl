#include "matrix.h"

template <typename T>
Matrix<T>::Matrix (int size_x, int size_y, initializer_list<initializer_list<T>> matrix)
    {
    size_x_ = size_x;
    size_y_ = size_y;

    matrix_ = new T*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new T[size_x_];
                            
    int y = 0, x = 0;

    for (auto row: matrix)
        {
        for (auto elem: row)
            {
            matrix_[y][x] = elem;
            x++;
            }
        x = 0;
        y++;
        }
    }

template <typename T>
Matrix<T>::Matrix (int size_x, int size_y, T** matrix)
    {
    size_x_ = size_x;
    size_y_ = size_y;

    matrix_ = new T*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new T [size_x_];

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            matrix_[y][x] = matrix[y][x];
    }

template <typename T>
Matrix<T>::Matrix (int size_x, int size_y)
    {
    size_x_ = size_x;
    size_y_ = size_y;

    matrix_ = new T*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new T [size_x_];

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            matrix_[y][x] = 0;
    }

template <typename T>
Matrix<T>::Matrix ()
    {
    size_x_ = 0;
    size_y_ = 0;

    matrix_ = new T*[1];
    for (int i = 0; i < 1; i++)
        matrix_[i] = new T [1];

    matrix_[0][0] = 0;
    }

//=========== exception ==========================================
Matrix<char>::Matrix ()
    {
    size_x_ = 0;
    size_y_ = 0;

    matrix_ = new char*[1];
    for (int i = 0; i < 1; i++)
        matrix_[i] = new char [1];

    matrix_[0][0] = 'a';
    }

Matrix<string>::Matrix ()
    {
    size_x_ = 0;
    size_y_ = 0;

    matrix_ = new string*[1];
    for (int i = 0; i < 1; i++)
        matrix_[i] = new string [1];

    matrix_[0][0] = 'a';
    }
//================================================================

template <typename T>
Matrix<T>::Matrix (const Matrix<T> &matrix1)
    {
    size_x_ = matrix1.size_x_;
    size_y_ = matrix1.size_y_;

    matrix_ = new T*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new T [size_x_];

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            matrix_[y][x] = matrix1.matrix_[y][x];      
    }

template <typename T>
Matrix<T>::~Matrix ()
    {
    for (int i = 0; i < size_y_; i++)
        delete[] matrix_[i];
    }

template <typename T>
T* Matrix<T>::operator[] (const int index)
    {
    return matrix_[index];
    }

template <typename T>
ostream& operator<< (ostream &out, const Matrix<T> &matrix)
    {
    for (int y = 0; y < matrix.size_y_ - 1; y++)
        {
        out << "|";
        for (int x = 0; x < matrix.size_x_ - 1; x++)
            out << matrix.matrix_[y][x] << " ";
        out << matrix.matrix_[y][matrix.size_x_ - 1] << "|" << '\n';
        }

    if (matrix.size_y_ != 0)
        {
        out << "|";
        for (int x = 0; x < matrix.size_x_ - 1; x++)
            out << matrix.matrix_[matrix.size_y_ - 1][x] << " ";
        out << matrix.matrix_[matrix.size_y_ - 1][matrix.size_x_ - 1] << "|";
        }
        
    return out;
    }

template <typename T>
istream& operator>> (istream& in, Matrix<T> &matrix)
    {
    printf ("Enter x: ");
    in >> matrix.size_x_;
    printf("Enter y: ");
    in >> matrix.size_y_;

    matrix.matrix_ = new T*[matrix.size_y_];
    for (int i = 0; i < matrix.size_y_; i++)
        matrix.matrix_[i] = new T [matrix.size_x_];

    printf("Enter matrix:\n");
    for (int y = 0; y < matrix.size_y_; y++)
        for (int x = 0; x < matrix.size_x_; x++)
            in >> matrix.matrix_[y][x];          
    return in;
    }

template <typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T> &rhs)
    {
    Matrix temp (size_x_, size_y_);
    
    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            temp.matrix_[y][x] += rhs.matrix_[y][x];
    return temp; 
    }

//=========== exception ==========================================
Matrix<char> Matrix<char>::operator+ (const Matrix<char> &rhs)
    {
    cout << "You cannot add \"char\" types\n";
    return Matrix<char>();
    } 
//================================================================

template <typename T>
Matrix<T> Matrix<T>::operator- (const Matrix<T> &rhs)
    {
    Matrix temp (size_x_, size_y_);

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            temp.matrix_[y][x] -= rhs.matrix_[y][x];
    return temp;
    }

//=========== exception ==========================================
Matrix<char> Matrix<char>::operator- (const Matrix<char> &rhs)
    {
    cout << "You cannot subtract \"char\" types\n";
    return Matrix<char>();
    } 

Matrix<string> Matrix<string>::operator- (const Matrix<string> &rhs)
    {
    cout << "You cannot subtract \"string\" types\n";
    return Matrix<string>();
    }
//================================================================

template <typename T>
Matrix<T> Matrix<T>::operator* (const Matrix<T> &rhs)
    {
    Matrix temp (rhs.size_x_, size_y_);

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < rhs.size_x_; x++)
            for (int k = 0; k < size_x_; k++)
                temp.matrix_[y][x] += matrix_[y][k] * rhs.matrix_[k][x];
                
    return temp;
    }

//=========== exception ==========================================
Matrix<char> Matrix<char>::operator* (const Matrix<char> &rhs)
    {
    cout << "You cannot multiply \"char\" types\n";
    return Matrix<char>();
    } 

Matrix<string> Matrix<string>::operator* (const Matrix<string> &rhs)
    {
    cout << "You cannot multiply \"string\" types\n";
    return Matrix<string>();
    }
//================================================================

template <typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T> &matrix)
    {
    this->~Matrix();

    size_x_ = matrix.size_x_;
    size_y_ = matrix.size_y_;

    matrix_ = new T*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new T [size_x_];


    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            matrix_[y][x] = matrix.matrix_[y][x];  

    return *this;   
    }

template <typename T>
Matrix<T> Matrix<T>::operator* (const int rhs)
    {
    Matrix temp = *this;

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            temp.matrix_[y][x] *= rhs;

    return temp;
    }

//=========== exception ==========================================
Matrix<char> Matrix<char>::operator* (const int rhs)
    {
    cout << "You cannot multiply \"char\" by \"int\" types\n";
    return Matrix<char>();
    } 
//================================================================

template <typename T>
Matrix<T> Matrix<T>::operator*=  (const Matrix<T>& rhs)
    {
    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < rhs.size_x_; x++)
            for (int k = 0; k < size_x_; k++)
                matrix_[y][x] *= matrix_[y][k] * rhs.matrix_[k][x];
    return *this;
    }

//=========== exception ==========================================
Matrix<char> Matrix<char>::operator*= (const Matrix<char> &rhs)
    {
    cout << "You cannot multiply \"char\" types\n";
    return Matrix<char>();
    } 

Matrix<string> Matrix<string>::operator*= (const Matrix<string> &rhs)
    {
    cout << "You cannot multiply \"string\" types\n";
    return Matrix<string>();
    }
//================================================================

template <typename T>
Matrix<T>& Matrix<T>::Tran()
    {
    Matrix temp (size_y_, size_x_);

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            temp.matrix_[x][y] = matrix_[y][x];

    *this = temp;
    
    return temp;
    }

template <typename T>
bool Matrix<T>::is_right_step()
    {  
    int first_not_null = -1;

    while (matrix_[0][first_not_null++] == 0);
        
    
    for (int y = 1; y < size_y_; y++)
        {  
        bool is_null = 1;
        for (int x = 0; x < size_x_; x++)
            {
            if (matrix_[y][x] != 0)
                {
                is_null = 0;
                if (x < first_not_null)
                    return false;
                else
                    first_not_null = x;
                break;
                }
            }
        if (is_null)
            first_not_null = size_x_;
        }
            
    return true;
    }

//=========== exception ==========================================
bool Matrix<char>::is_right_step()
    {
    cout << "You cannot check for right step \"char\" matrix types\n";
    return 0;
    } 

bool Matrix<string>::is_right_step()
    {
    cout << "You cannot check for right step \"string\" matrix types\n";
    return 0;
    }
//================================================================

template <typename T>
int Matrix<T>::get_size_x()
    {
    return size_x_;
    }

template <typename T>
int Matrix<T>::get_size_y()    
    {
    return size_y_;
    }

template <typename T>
Matrix<T> Matrix<T>::get_identity_matrix ()
    {
    Matrix temp (size_x_, size_y_);

    for (int i = 0; i < size_x_; i++)
        temp[i][i] = 1;

    return temp;
    }

//=========== exception ==========================================
Matrix<char> Matrix<char>::get_identity_matrix ()
    {
    cout << "There is no identity matrix of \"char\" \n";
    return Matrix<char>();
    } 

Matrix<string> Matrix<string>::get_identity_matrix ()
    {
    cout << "There is no identity matrix of \"string\" \n";
    return Matrix<string>();
    }
//================================================================

template <typename T>
Matrix<T> Matrix<T>::pow (int power)
    {
    if (power == 0)
        return this->get_identity_matrix();
    if (power % 2 == 1)
        return this->pow(power - 1) * *this;
    else
        {
        Matrix temp = this->pow(power / 2);
        return temp * temp;
        }
    }

//=========== exception ==========================================
Matrix<char> Matrix<char>::pow (int power)
    {
    cout << "There is no function pow for \"char\" \n";
    return Matrix<char>();
    } 

Matrix<string> Matrix<string>::pow (int power)
    {
    cout << "There is no function pow for \"string\" \n";
    return Matrix<string>();
    }
//================================================================

template <typename T>
T Matrix<T>::determinant()
    {
    if (size_x_ != size_y_)
        {
        cout << "you can determinant only square matrix";  
        return 0;
        }
    int det = 0;
    if (size_x_ == 1)
        return matrix_[0][0];
    else if (size_x_ == 2)
        return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    else
        {
        int s = 1;
        for (int k = 0; k < size_x_; k++)
            {
            Matrix temp (size_x_ - 1, size_y_ - 1);       
            for (int i = 1; i < size_x_; i++)
                {
                int t = 0;
                for (int j = 0; j < size_x_; j++)   
                    {
                    if (j == k)
                        continue;
                    temp.matrix_[i - 1][t++] = matrix_[i][j];
                    }
                }
            det += s * matrix_[0][k] * temp.determinant();  
            s *= -1;
            }
        }

    return det;
    }

//=========== exception ==========================================
char Matrix<char>::determinant()
    {
    cout << "There is no determinant for \"char\" \n";
    return 0;
    } 

string Matrix<string>::determinant()
    {
    cout << "There is no determinant for \"string\" \n";
    return 0;
    }
//================================================================