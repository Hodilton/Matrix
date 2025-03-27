#include "./size.h"

namespace matrix {

	Size::Size()
		: _rows(1), _cols(1) {
	}

	Size::Size(size_t rows, size_t cols)
		: _rows(rows), _cols(cols) {
	}

	size_t Size::getRows() const {
		return _rows;
	}

	size_t Size::getCols() const {
		return _cols;
	}
}