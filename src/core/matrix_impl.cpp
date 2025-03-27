#ifndef MATRIX_IMPL_CPP
#define MATRIX_IMPL_CPP
#include "./matrix_impl.h"

namespace matrix::core {

	template<typename T>
	inline MatrixImpl<T>::MatrixImpl(size_t rows, size_t cols)
	{
		_elements.resize(rows, std::vector<T>(cols));
	}

	template<typename T>
	MatrixImpl<T>::MatrixImpl(const std::vector<std::vector<T>>& values)
		: _size(values.size(), values.empty()
			? 0
			: values[0].size()), _elements(values) {
	}

	template<typename T>
	size_t MatrixImpl<T>::getRows() const
	{
		return size_t();
	}

	template<typename T>
	size_t MatrixImpl<T>::getCols() const
	{
		return size_t();
	}

	template<typename T>
	Size MatrixImpl<T>::getSize() const
	{
		return Size();
	}

	template<typename T>
	T& MatrixImpl<T>::operator()(size_t row, size_t col)
	{
		return _elements[row][col];
	}

	template<typename T>
	const T& MatrixImpl<T>::operator()(size_t row, size_t col) const
	{
		return _elements[row][col];
	}
}

#endif // !MATRIX_IMPL_CPP