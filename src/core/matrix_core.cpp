#ifndef MATRIX_CORE_CPP
#define MATRIX_CORE_CPP
#include "./matrix_core.h"

namespace matrix::core {

	template<typename T>
	inline MatrixCore<T>::MatrixCore(size_t rows, size_t cols)
	{
		_elements.resize(rows, std::vector<T>(cols));
	}

	template<typename T>
	MatrixCore<T>::MatrixCore(const std::vector<std::vector<T>>& values)
		: _size(values.size(), values.empty()
			? 0
			: values[0].size()), _elements(values) {
	}

	template<typename T>
	size_t MatrixCore<T>::getRows() const
	{
		return size_t();
	}

	template<typename T>
	size_t MatrixCore<T>::getCols() const
	{
		return size_t();
	}

	template<typename T>
	Size MatrixCore<T>::getSize() const
	{
		return Size();
	}

	template<typename T>
	T& MatrixCore<T>::operator()(size_t row, size_t col)
	{
		return _elements[row][col];
	}

	template<typename T>
	const T& MatrixCore<T>::operator()(size_t row, size_t col) const
	{
		return _elements[row][col];
	}
}

#endif // !MATRIX_CORE_CPP