#ifndef MATRIX_H
#define MATRIX_H

#include "../src/core/size.h"
#include "../src/core/matrix_core.h"

#include "../src/decorators/arithmetic_decorator.h"
//#include "../src/decorators/comparison_decorator.h"
//#include "../src/decorators/math_operations_decorator.h"
#include "../src/decorators/serialization_decorator.h"

namespace matrix {

    template <typename T>
    class Matrix : public core::MatrixCore<T>{
    private:
        decorators::ArithmeticDecorator<T>* _arithmeticDecorator;
        //std::unique_ptr<Decorators::ComparisonDecorator<T>> comparisonDecorator;
        //std::unique_ptr<Decorators::MathOperationsDecorator<T>> mathOperationsDecorator;
        decorators::SerializationDecorator<T>* _serializationDecorator;

    public:
        Matrix();
        Matrix(size_t rows, size_t cols);
        Matrix(const Size& size);
        Matrix(const std::vector<std::vector<T>>& values);
        Matrix(const Matrix<T>& other);
        ~Matrix();

    private:
        void initDecorators();

    public:
        Matrix<T> operator+(const Matrix<T>& other) const;
        Matrix<T> operator-(const Matrix<T>& other) const;
        Matrix<T> operator*(const Matrix<T>& other) const;

        Matrix<T> operator+(const T& value) const;
        Matrix<T> operator-(const T& value) const;
        Matrix<T> operator*(const T& value) const;
        Matrix<T> operator/(const T& value) const;

        Matrix<T>& operator+=(const Matrix<T>& other);
        Matrix<T>& operator-=(const Matrix<T>& other);
        Matrix<T>& operator*=(const Matrix<T>& other);

        Matrix<T>& operator+=(const T& value);
        Matrix<T>& operator-=(const T& value);
        Matrix<T>& operator*=(const T& value);
        Matrix<T>& operator/=(const T& value);

        //bool operator==(const Matrix<T>& other) const;
        //bool operator!=(const Matrix<T>& other) const;
        //bool operator<(const Matrix<T>& other) const;
        //bool operator<=(const Matrix<T>& other) const;
        //bool operator>(const Matrix<T>& other) const;
        //bool operator>=(const Matrix<T>& other) const;

        //Matrix<T> transpose() const;
        //T determinant() const;
        //Matrix<T> inverse() const;

        //T sum() const;
        //T sumRow(size_t row) const;
        //T sumColumn(size_t col) const;

        template<typename U>
        friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
        template<typename U>
        friend std::istream& operator>>(const std::istream& in, Matrix<U>& matrix);
    };
}

#include "../src/matrix.cpp"
#endif // !MATRIX_H