#pragma once
#include <iostream>



//template <typename T>
class MatrixClass {
public:
    double** matrix;
    int rows; //������
    int cols; //�������
    MatrixClass();
    MatrixClass(int _cols, int _rows);
    MatrixClass(const MatrixClass& _matrix);
    ~MatrixClass();
    double Get(int i, int j);
    void Set(int i, int j, double value);
    MatrixClass operator=(const MatrixClass& _matrix);
    friend MatrixClass operator-(double left, const MatrixClass& right);
    friend MatrixClass operator-(const MatrixClass& left, double right);
    friend MatrixClass operator-(const MatrixClass& left, const MatrixClass& right);
    friend MatrixClass operator+(const MatrixClass& left, const MatrixClass& right);
    friend MatrixClass operator+(double left, const MatrixClass& right);
    friend MatrixClass operator+(const MatrixClass& left, double right);
    friend MatrixClass operator*(const MatrixClass& left, const MatrixClass& right);
    friend MatrixClass operator*(double left, const MatrixClass& right);
    friend MatrixClass operator*(const MatrixClass& left, double right);
    friend MatrixClass operator/(const MatrixClass& left, const MatrixClass& right);
    friend MatrixClass operator/(double left, const MatrixClass& right);
    friend MatrixClass operator/(const MatrixClass& left, double right);
    friend MatrixClass operator+=(MatrixClass& left, const MatrixClass& right);
    friend MatrixClass operator-=(MatrixClass& left, const MatrixClass& right);
    friend MatrixClass operator*=(MatrixClass& left, const MatrixClass& right);
    friend MatrixClass operator/=(MatrixClass& left, const MatrixClass& right);
    friend MatrixClass operator+=(MatrixClass& left, const double right);
    friend MatrixClass operator-=(MatrixClass& left, const double right);
    friend MatrixClass operator*=(MatrixClass& left, const double right);
    friend MatrixClass operator/=(MatrixClass& left, const double right);
    friend MatrixClass operator++(MatrixClass& M);
    friend MatrixClass operator--(MatrixClass& M);
    friend MatrixClass operator++(MatrixClass& M);
    friend MatrixClass operator--(MatrixClass& M);
    friend std::ostream& operator<< (std::ostream& out, const MatrixClass& M);
};