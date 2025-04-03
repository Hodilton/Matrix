#ifndef MATRIX_COMPARISON_DECORATOR_CPP
#define MATRIX_COMPARISON_DECORATOR_CPP
#include "./comparison_decorator.h"

namespace matrix::decorators {

	template<typename T>
	ComparisonDecorator<T>::ComparisonDecorator() 
		: _matrix(nullptr) {
	}

	template<typename T>
	ComparisonDecorator<T>::ComparisonDecorator(core::MatrixCore<T>& matrix)
		: _matrix(&matrix) {
	}

	template<typename T>
	ComparisonDecorator<T>::~ComparisonDecorator() {
	}

	template<typename T>
	bool ComparisonDecorator<T>::isSameSize(const Matrix<T>& other) const {
		return _matrix->getRows() == other.getRows() &&
			   _matrix->getCols() == other.getCols();
	}

	template<typename T>
	bool ComparisonDecorator<T>::isSquare() const {
		return _matrix->getRows() == _matrix->getCols();
	}

	template<typename T>
	bool ComparisonDecorator<T>::isSymmetric() const {
		if (!isSquare()) return false;
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < i; ++j) {
				if (!isEqual((*_matrix)(i, j), (*_matrix)(j, i))) {
					return false;
				}
			}
		} return true;
	}

	template<typename T>
	bool ComparisonDecorator<T>::isZero() const {
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				if (!isEqual((*_matrix)(i, j), T(0))) {
					return false;
				}
			}
		} return true;
	}

	template<typename T>
	bool ComparisonDecorator<T>::isIdentity() const {
		if (!isSquare()) return false;
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				const T value = (*_matrix)(i, j);
				if ((i == j && !isEqual(value, T(1))) ||
					(i != j && !isEqual(value, T(0)))) {
					return false;
				}
			}
		} return true;
	}

	template<typename T>
	bool ComparisonDecorator<T>::operator==(const Matrix<T>& other) const {
		if (!isSameSize(other)) return false;
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				if (!isEqual((*_matrix)(i, j), other(i, j))) {
					return false;
				}
			}
		} return true;
	}

	template<typename T>
	bool ComparisonDecorator<T>::operator!=(const Matrix<T>& other) const {
		return !(*_matrix == other);
	}

	template<typename T>
	bool ComparisonDecorator<T>::operator<(const Matrix<T>& other) const {
		if (!isSameSize(other)) return false;
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				if ((*_matrix)(i, j) >= other(i, j)) {
					return false;
				}
			}
		} return true;
	}

	template<typename T>
	bool ComparisonDecorator<T>::operator<=(const Matrix<T>& other) const {
		if (!isSameSize(other)) return false;
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				if ((*_matrix)(i, j) > other(i, j)) {
					return false;
				}
			}
		} return true;
	}

	template<typename T>
	bool ComparisonDecorator<T>::operator>(const Matrix<T>& other) const {
		return !(*_matrix < other);
	}

	template<typename T>
	bool ComparisonDecorator<T>::operator>=(const Matrix<T>& other) const {
		return !(*_matrix <= other);
	}

	template<typename T>
	bool ComparisonDecorator<T>::isEqual(T a, T b) const {
		return std::fabs(a - b) < EPSILON;
	}
}

#endif // !MATRIX_COMPARISON_DECORATOR_CPP