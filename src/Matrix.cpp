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
	}

	template<typename T>
	void Matrix<T>::initDecorators() {
		_arithmeticDecorator = new decorators::ArithmeticDecorator<T>(*this);
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
	{
		core::MatrixCore<T> resultImpl = _arithmeticDecorator + other;
		return Matrix<T>(resultImpl);
	}
}

#endif // !MATRIXL_CPP