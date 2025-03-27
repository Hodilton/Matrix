#include "./size.h"

namespace matrix {
	Size::Size(size_t rows, size_t cols)
		: _rows(rows), _cols(cols) {}

	Size::Size()
		: _rows(1), _cols(1) {
	}

	size_t Size::getRows() const
	{
		return size_t();
	}

	size_t Size::getCols() const
	{
		return size_t();
	}
}