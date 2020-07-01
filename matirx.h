#include <iostream>
#include <vector>

template <typename T>
class Matrix {
    T** matrix; 
    int rows; //строки
    int cols; //столбцы
public:
    //Конструкторы 
    //без параметров
    Matrix();
    //Два параметра
    Matrix(int _cols, int _rows)
    {
        rows = _rows;
        cols = _cols;

        //Массив указателей
        matrix = (T**) new T * [rows];

        //Выделить память для каждого указателя
        for (int i = 0; i < rows; i++)
            matrix[i] = (T*)new T[cols];

        //Заполнение матрицы нулями
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++ )
                matrix[i][j] = 0;
    };
    //Копирование
    Matrix(const Matrix& _matrix)
    {
        rows = _matrix.rows;
        cols = _matrix.cols;

        matrix = (T**) new T * [rows];

        for (int i = 0; i < rows; i++)
            matrix[i] = (T*)new T[cols];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = _matrix.matrix[i][j];
    }
    //Деструктор
    ~Matrix()
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
    void Get(int i, int j)
    {
        if ((rows > 0) && (cols > 0))
            return matrix[i][j];
        else
            return 0;
    }
    //Метод доступа Set
    void Set(int i, int j, T value)
    {
        if ((i < 0) || (i >= rows))
            return;
        if ((j < 0) || (j >= cols))
            return;
        matrix[i][j] = value;
    }
    Matrix operator=(const Matrix& _matrix)
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
        matrix = (T**) new T * [rows]; // количество строк, количество указателей
        for (int i = 0; i < rows; i++)
            matrix[i] = (T*) new T[cols];

        // заполнить значениями
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = _matrix.matrix[i][j];
        return *this;
    }
    friend const Matrix operator-(double left, const Matrix& right)
    {
        Matrix temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left - right.matrix[i][j];
        return temp;
    }
    friend const Matrix operator-(const Matrix& left, double right)
    {
        Matrix temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right;
        return temp;
    }
    friend const Matrix operator-(const Matrix& left, const Matrix& right)
    {
        Matrix temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        return temp;
    }
    friend const Matrix operator+(const Matrix& left, const Matrix& right)
    {
        Matrix temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        return temp;
    }
    friend const Matrix operator+(const Matrix& left, double right)
    {
        Matrix temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right;
        return temp;
    }
    friend const Matrix operator+(double left, const Matrix& right)
    {
        Matrix temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left * right.matrix[i][j];
        return temp;
    }
    friend const Matrix operator*(const Matrix& left, const Matrix& right)
    {
        Matrix temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] * right.matrix[i][j];
        return temp;
    }
    friend const Matrix operator*(const Matrix& left, double right)
    {
        Matrix temp(left.cols, left.rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] * right;
        return temp;
    }
    friend const Matrix operator*(double left, const Matrix& right)
    {
        Matrix temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left * right.matrix[i][j];
        return temp;
    }
    friend const Matrix operator/(const Matrix& left, const Matrix& right)
    {
        Matrix temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.martix[i][j] / right.matrix[i][j];
        return temp;
    }
    friend const Matrix operator/(const Matrix& left, double right)
    {
        Matrix temp(left.cols, left.rows);
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] / right;
        return temp;
    }
    friend const Matrix operator/(double left, const Matrix& right)
    {
        Matrix temp(right.cols, right.rows);
        for (int i = 0; i < right.rows; i++)
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left / right.matrix[i][j];
        return temp;
    }
    friend const Matrix& operator+=(Matrix& left, const Matrix& right)
    { 
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] += right.matrix[i][j];
        return left;
    }
    friend const Matrix& operator-=(Matrix& left, const Matrix& right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] -= right.matrix[i][j];
        return left;
    }
    friend const Matrix operator*=(Matrix& left, const Matrix& right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] *= right.matrix[i][j];
        return left;
    }
    friend const Matrix operator/=(Matrix& left, const Matrix& right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] /= right.matrix[i][j];
        return left;
    }
    friend const Matrix operator+=(Matrix& left, const double right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] += right;
        return left;
    }
    friend const Matrix operator-=(Matrix& left, const double right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] -= right;
        return left;
    }
    friend const Matrix operator*=(Matrix& left, const double right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] *= right;
        return left;
    }
    friend const Matrix operator/=(Matrix& left, const double right)
    {
        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.cols; j++)
                left.matrix[i][j] /= right;
        return left;
    }
    //Инкремент и декремент увеличивают/уменьшают значения всех элементов на 1
    //Префиксный инкремент 
    friend const Matrix& operator++(Matrix& M)
    {
        for (int i = 0; i < M.rows; i++)
            for (int j = 0; j < M.cols; j++)
                M.matrix[i][j] = M.matrix[i][j] + 1;
        return M;
    }
    //Постфиксный инкремент
    friend const Matrix operator++(Matrix& M, int)
    {
        Matrix oldValue(M);
        for (int i = 0; i < M.rows; i++)
            for (int j = 0; j < M.cols; j++)
                M.matrix[i][j] = M.matrix[i][j] + 1;
        return oldValue;
    }
    //Префиксный декремент 
    friend const Matrix& operator--(Matrix& M)
    {
        for (int i = 0; i < M.rows; i++)
            for (int j = 0; j < M.cols; j++)
                M.matrix[i][j] = M.matrix[i][j] - 1;
        return M;
    }
    //Постфиксный декремент
    friend const Matrix operator--(Matrix& M, int)
    {
        Matrix oldValue(M);
        for (int i = 0; i < M.rows; i++)
            for (int j = 0; j < M.cols; j++)
                M.matrix[i][j] = M.matrix[i][j] - 1;
        return oldValue;
    }

    friend std::ostream& operator<< (std::ostream &out, const Matrix &M);
};

//Перегрузка оператора вывода
std::ostream& operator<< (std::ostream &out, const Matrix<double> &M)
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

int main()
{
    
}
