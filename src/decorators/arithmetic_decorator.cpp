#ifndef MATRIX_ARITHMETIC_DECORATOR_CPP
#define MATRIX_ARITHMETIC_DECORATOR_CPP
#include "./arithmetic_decorator.h"

namespace matrix::decorators {

	template<typename T>
	ArithmeticDecorator<T>::ArithmeticDecorator()
		: _matrix(nullptr) {
	}

	template<typename T>
	ArithmeticDecorator<T>::ArithmeticDecorator(core::MatrixCore<T>& matrix)
		: _matrix(&matrix) {
	}

	template<typename T>
	ArithmeticDecorator<T>::~ArithmeticDecorator() {
	}

	template<typename T>
	Matrix<T> ArithmeticDecorator<T>::operator+(const Matrix<T>& other) const {
		if (_matrix->getRows() != other.getRows() || _matrix->getCols() != other.getCols()) {
			throw std::invalid_argument("Matrix dimensions must match for addition.");
		}

		Matrix<T> result(_matrix->getSize());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				result(i, j) = (*_matrix)(i, j) + other(i, j);
			}
		} return result;
	}

	template<typename T>
	Matrix<T> ArithmeticDecorator<T>::operator-(const Matrix<T>& other) const {
		if (_matrix->getRows() != other.getRows() || _matrix->getCols() != other.getCols()) {
			throw std::invalid_argument("Matrix dimensions must match for subtraction.");
		}

		Matrix<T> result(_matrix->getSize());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				result(i, j) = (*_matrix)(i, j) - other(i, j);
			}
		} return result;
	}

	template<typename T>
	Matrix<T> ArithmeticDecorator<T>::operator*(const Matrix<T>& other) const {
		if (_matrix->getCols() != other.getRows()) {
			throw std::invalid_argument("Matrix dimensions must match for multiplication.");
		}

		Matrix<T> result(_matrix->getRows(), other.getCols());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < other.getCols(); ++j) {
				T sum = T{};
				for (size_t k = 0; k < _matrix->getCols(); ++k) {
					sum += (*_matrix)(i, k) * other(k, j);
				} result(i, j) = sum;
			}
		} return result;
	}

	template<typename T>
	Matrix<T> ArithmeticDecorator<T>::operator+(const T& value) const {
		Matrix<T> result(_matrix->getSize());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				result(i, j) = (*_matrix)(i, j) + value;
			}
		} return result;
	}

	template<typename T>
	Matrix<T> ArithmeticDecorator<T>::operator-(const T& value) const {
		Matrix<T> result(_matrix->getSize());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				result(i, j) = (*_matrix)(i, j) - value;
			}
		} return result;
	}

	template<typename T>
	Matrix<T> ArithmeticDecorator<T>::operator*(const T& value) const {
		Matrix<T> result(_matrix->getSize());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				result(i, j) = (*_matrix)(i, j) * value;
			}
		} return result;
	}

	template<typename T>
	Matrix<T> ArithmeticDecorator<T>::operator/(const T& value) const {
		if (value == T{}) {
			throw std::invalid_argument("Division by zero.");
		}

		Matrix<T> result(_matrix->getSize());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				result(i, j) = (*_matrix)(i, j) / value;
			}
		} return result;
	}
	
	template<typename T>
	ArithmeticDecorator<T>& ArithmeticDecorator<T>::operator+=(const core::MatrixCore<T>& other) {
		*_matrix = *_matrix + other;
		return *this;
	}

	template<typename T>
	ArithmeticDecorator<T>& ArithmeticDecorator<T>::operator-=(const core::MatrixCore<T>& other) {
		*_matrix = *_matrix - other;
		return *this;
	}
	
	template<typename T>
	ArithmeticDecorator<T>& ArithmeticDecorator<T>::operator*=(const core::MatrixCore<T>& other) {
		*_matrix = *_matrix * other;
		return *this;
	}

	template<typename T>
	ArithmeticDecorator<T>& ArithmeticDecorator<T>::operator+=(const T& value) {
		*_matrix = *_matrix + value;
		return *this;
	}

	template<typename T>
	ArithmeticDecorator<T>& ArithmeticDecorator<T>::operator-=(const T& value) {
		*_matrix = *_matrix - value;
		return *this;
	}

	template<typename T>
	ArithmeticDecorator<T>& ArithmeticDecorator<T>::operator*=(const T& value) {
		*_matrix = *_matrix * value;
		return *this;
	}

	template<typename T>
	ArithmeticDecorator<T>& ArithmeticDecorator<T>::operator/=(const T& value) {
		*_matrix = *_matrix / value;
		return *this;
	}
}

#endif // !MATRIX_ARITHMETIC_DECORATOR_CPP