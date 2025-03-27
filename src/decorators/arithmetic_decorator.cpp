#ifndef MATRIX_DECORATORS_CPP
#define MATRIX_DECORATORS_CPP
#include "./arithmetic_decorator.h"

namespace matrix::decorators {

	template<typename T>
	inline ArithmeticDecorator<T>::ArithmeticDecorator(core::MatrixCore<T>& m)
		: matrix(m) {
	}

	template<typename T>
	core::MatrixCore<T> ArithmeticDecorator<T>::operator+(const core::MatrixCore<T>& other) const
	{
		return core::MatrixCore<T>();
	}

	template<typename T>
	core::MatrixCore<T> ArithmeticDecorator<T>::operator-(const core::MatrixCore<T>& other) const
	{
		return core::MatrixCore<T>();
	}

	template<typename T>
	core::MatrixCore<T> ArithmeticDecorator<T>::operator*(const core::MatrixCore<T>& other) const
	{
		return core::MatrixCore<T>();
	}

	template<typename T>
	core::MatrixCore<T> ArithmeticDecorator<T>::operator+(const T& value) const
	{
		return core::MatrixCore<T>();
	}

	template<typename T>
	core::MatrixCore<T> ArithmeticDecorator<T>::operator-(const T& value) const
	{
		return core::MatrixCore<T>();
	}

	template<typename T>
	core::MatrixCore<T> ArithmeticDecorator<T>::operator*(const T& value) const
	{
		return core::MatrixCore<T>();
	}

	template<typename T>
	core::MatrixCore<T> ArithmeticDecorator<T>::operator/(const T& value) const
	{
		return core::MatrixCore<T>();
	}
}

#endif // !MATRIX_DECORATORS_CPP