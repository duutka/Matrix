#include <iostream>
#include "matrix.h"
//template<typename T>
//using MatrixClass = MatrixClass::MatrixClass<double>;
     MatrixClass::MatrixClass() {};
     //Два параметра
    MatrixClass::MatrixClass(int _cols, int _rows)
    {
        rows = _rows;
        cols = _cols;

        //Массив указателей
        matrix = (double**) new double* [rows];

        //Выделить память для каждого указателя
        for (int i = 0; i < rows; i++)
            matrix[i] = (double*)new double[cols];

        //Заполнение матрицы нулями
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++ )
                matrix[i][j] = 0;
    };
    //Копирование
    MatrixClass::MatrixClass(const MatrixClass& _matrix)
    {
        rows = _matrix.rows;
        cols = _matrix.cols;

        matrix = (double**) new double * [rows];

        for (int i = 0; i < rows; i++)
            matrix[i] = (double*)new double[cols];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = _matrix.matrix[i][j];
    }
    //Деструктор
    MatrixClass::~MatrixClass()
    {
        if (cols > 0)
        {
            for (int i = 0; i < rows; i++)
                delete[] matrix[i];
        }
        if (rows > 0)
            delete[] matrix;
    }
    //Метод доступа Get
    double MatrixClass::Get(int i, int j)
    {
        if ((rows > 0) && (cols > 0))
            return matrix[i][j];
        else
            return 0;
    }
    //Метод доступа Set
    void MatrixClass::Set(int _rows, int _cols, double value)
    {
        if ((_rows < 0) || (_rows >= rows))
            return;
        if ((_cols < 0) || (_cols >= cols))
            return;
        matrix[_rows][_cols] = value;
    }
 
    MatrixClass MatrixClass::operator=(const MatrixClass& _matrix)
    {
        if (cols > 0)
        {
            // освободить память, выделенную ранее для объекта *this
            for (int i = 0; i < rows; i++)
                delete[] matrix[i];
        }

        if (rows > 0)
        {
            delete[] matrix;
        }

        // Копирование данных 
        rows = _matrix.rows;
        cols = _matrix.cols;

        // Выделить память для M опять
        matrix = (double**) new double* [rows]; // количество строк, количество указателей
        for (int i = 0; i < rows; i++)
            matrix[i] = (double*) new double[cols];

        // заполнить значениями
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = _matrix.matrix[i][j];
        return *this;
    }
    MatrixClass operator-(double left, const MatrixClass& right)
    {
        MatrixClass temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left - right.matrix[i][j];
        return temp;
    }
    MatrixClass operator-(const MatrixClass& left, double right)
    {
        MatrixClass temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right;
        return temp;
    }
    MatrixClass operator-(const MatrixClass& left, const MatrixClass& right)
    {
        MatrixClass temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        return temp;
    }
    MatrixClass operator+(const MatrixClass& left, const MatrixClass& right)
    {
        MatrixClass temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        return temp;
    }
    MatrixClass operator+(const MatrixClass& left, double right)
    {
        MatrixClass temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right;
        return temp;
    }
    MatrixClass operator+(double left, const MatrixClass& right)
    {
        MatrixClass temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left + right.matrix[i][j];
        return temp;
    }
    MatrixClass operator*(const MatrixClass& left, const MatrixClass& right)
    {
        MatrixClass temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] * right.matrix[i][j];
        return temp;
    }
    MatrixClass operator*(const MatrixClass& left, double right)
    {
        MatrixClass temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] * right;
        return temp;
    }
    MatrixClass operator*(double left, const MatrixClass& right)
    {
        MatrixClass temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left * right.matrix[i][j];
        return temp;
    }
    MatrixClass operator/(const MatrixClass& left, const MatrixClass& right)
    {
        MatrixClass temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] / right.matrix[i][j];
        return temp;
    }
    MatrixClass operator/(const MatrixClass& left, double right)
    {
        MatrixClass temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] / right;
        return temp;
    }
    MatrixClass operator/(double left, const MatrixClass& right)
    {
        MatrixClass temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left / right.matrix[i][j];
        return temp;
    }
    MatrixClass operator+=(MatrixClass& left, const MatrixClass& right)
    { 
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] += right.matrix[i][j];
        return left;
    }
    MatrixClass operator-=(MatrixClass& left, const MatrixClass& right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] -= right.matrix[i][j];
        return left;
    }
    MatrixClass operator*=(MatrixClass& left, const MatrixClass& right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] *= right.matrix[i][j];
        return left;
    }
    MatrixClass operator/=(MatrixClass& left, const MatrixClass& right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] /= right.matrix[i][j];
        return left;
    }
    MatrixClass operator+=(MatrixClass& left, const double right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] += right;
        return left;
    }
    MatrixClass operator-=(MatrixClass& left, const double right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] -= right;
        return left;
    }
    MatrixClass operator*=(MatrixClass& left, const double right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] *= right;
        return left;
    }
    MatrixClass operator/=(MatrixClass& left, const double right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] /= right;
        return left;
    }
    //Инкремент и декремент увеличивают/уменьшают значения всех элементов на 1
    //Префиксный инкремент 
    MatrixClass operator++(MatrixClass& M)
    {
        for (int i = 0; i < M.rows; i++)
            for (int j = 0; j < M.cols; j++)
                M.matrix[i][j] = M.matrix[i][j] + 1;
        return M;
    }
    //Постфиксный инкремент
    MatrixClass operator++(MatrixClass& M, int)
    {
        MatrixClass oldValue(M);
        for (int i = 0; i < M.rows; i++)
            for (int j = 0; j < M.cols; j++)
                M.matrix[i][j] = M.matrix[i][j] + 1;
        return oldValue;
    }
    //Префиксный декремент 
    MatrixClass operator--(MatrixClass& M)
    {
        for (int i = 0; i < M.rows; i++)
            for (int j = 0; j < M.cols; j++)
                M.matrix[i][j] = M.matrix[i][j] - 1;
        return M;
    }
    //Постфиксный декремент
    MatrixClass operator--(MatrixClass& M, int)
    {
        MatrixClass oldValue(M);
        for (int i = 0; i < M.rows; i++)
            for (int j = 0; j < M.cols; j++)
                M.matrix[i][j] = M.matrix[i][j] - 1;
        return oldValue;
    }

std::ostream& operator<< (std::ostream &out, const MatrixClass &M)
{
    for (int i = 0; i < M.rows; i++)
    {
        for (int j = 0; j < M.cols; j++)
            out << M.matrix[i][j] << "\t";
        out << std::endl;
    }
    out << std::endl << std::endl;
    return out;
}
