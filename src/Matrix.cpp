#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "../include/matrix.h"

namespace matrix {

	template<typename T>
	Matrix<T>::Matrix()
		: core::MatrixCore<T>() {
		initDecorators();
	}

	template<typename T>
	Matrix<T>::Matrix(size_t rows, size_t cols)
		: core::MatrixCore<T>(rows, cols) {
		initDecorators();
    }

	template<typename T>
	Matrix<T>::Matrix(const Size& size)
		: core::MatrixCore<T>(size) {
		initDecorators();
	}

	template<typename T>
	Matrix<T>::Matrix(const std::vector<std::vector<T>>& values)
		: core::MatrixCore<T>(values) {
		initDecorators();
    }

	template<typename T>
	Matrix<T>::Matrix(const Matrix<T>& other)
		: core::MatrixCore<T>(other) {
		initDecorators();
	}

	template<typename T>
	Matrix<T>::~Matrix() {
		delete _arithmeticDecorator;
		delete _serializationDecorator;
	}

	template<typename T>
	void Matrix<T>::initDecorators() {
		_arithmeticDecorator = new decorators::ArithmeticDecorator<T>(*this);
		_serializationDecorator = new decorators::SerializationDecorator<T>(*this);
	}

    template <typename T>
    Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
        return _arithmeticDecorator.operator+(other);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
        return _arithmeticDecorator.operator-(other);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
        return _arithmeticDecorator.operator*(other);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator+(const T& value) const {
        return _arithmeticDecorator.operator+(value);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator-(const T& value) const {
        return _arithmeticDecorator.operator-(value);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator*(const T& value) const {
        return _arithmeticDecorator.operator*(value);
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator/(const T& value) const {
        return _arithmeticDecorator.operator/(value);
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other) {
        _arithmeticDecorator.operator+=(other);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other) {
        _arithmeticDecorator.operator-=(other);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& other) {
        _arithmeticDecorator.operator*=(other);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator+=(const T& value) {
        _arithmeticDecorator.operator+=(value);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator-=(const T& value) {
        _arithmeticDecorator.operator-=(value);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator*=(const T& value) {
        _arithmeticDecorator.operator*=(value);
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator/=(const T& value) {
        _arithmeticDecorator.operator/=(value);
        return *this;
    }

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
		if (matrix._serializationDecorator) {
			matrix._serializationDecorator->print(out);
		} return out;
	}

	template<typename T>
	std::istream& operator>>(const std::istream& in, Matrix<T>& matrix) {
		if (matrix._serializationDecorator) {
			matrix._serializationDecorator->read(in);;
		} return in;
	}
}

#endif // !MATRIXL_CPP