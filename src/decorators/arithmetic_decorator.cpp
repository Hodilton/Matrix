#ifndef MATRIX_DECORATORS_CPP
#define MATRIX_DECORATORS_CPP
#include "./arithmetic_decorator.h"

namespace matrix::decorators {

	template<typename T>
	inline ArithmeticDecorator<T>::ArithmeticDecorator(core::MatrixImpl<T>& m)
		: matrix(m) {
	}

	template<typename T>
	core::MatrixImpl<T> ArithmeticDecorator<T>::operator+(const core::MatrixImpl<T>& other) const
	{
		return core::MatrixImpl<T>();
	}

	template<typename T>
	core::MatrixImpl<T> ArithmeticDecorator<T>::operator-(const core::MatrixImpl<T>& other) const
	{
		return core::MatrixImpl<T>();
	}

	template<typename T>
	core::MatrixImpl<T> ArithmeticDecorator<T>::operator*(const core::MatrixImpl<T>& other) const
	{
		return core::MatrixImpl<T>();
	}

	template<typename T>
	core::MatrixImpl<T> ArithmeticDecorator<T>::operator+(const T& value) const
	{
		return core::MatrixImpl<T>();
	}

	template<typename T>
	core::MatrixImpl<T> ArithmeticDecorator<T>::operator-(const T& value) const
	{
		return core::MatrixImpl<T>();
	}

	template<typename T>
	core::MatrixImpl<T> ArithmeticDecorator<T>::operator*(const T& value) const
	{
		return core::MatrixImpl<T>();
	}

	template<typename T>
	core::MatrixImpl<T> ArithmeticDecorator<T>::operator/(const T& value) const
	{
		return core::MatrixImpl<T>();
	}
}

#endif // !MATRIX_DECORATORS_CPP