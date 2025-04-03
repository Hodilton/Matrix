#ifndef MATRIX_SERIALIZATION_DECORATOR_CPP
#define MATRIX_SERIALIZATION_DECORATOR_CPP
#include "./serialization_decorator.h"

namespace matrix::decorators {

    template<typename T>
    SerializationDecorator<T>::SerializationDecorator()
        : _matrix(nullptr) {
    }

    template<typename T>
    SerializationDecorator<T>::SerializationDecorator(core::MatrixCore<T>& matrix)
        : _matrix(&matrix) {
    }

    template<typename T>
    SerializationDecorator<T>::~SerializationDecorator() {
    }

    template<typename T>
    void SerializationDecorator<T>::print(std::ostream& out) const {
        if (!_matrix) {
            return;
        }

        for (size_t i = 0; i < _matrix->getRows(); ++i) {
            for (size_t j = 0; j < _matrix->getCols(); ++j) {
                out << (*_matrix)(i, j);
                if (j < _matrix->getCols() - 1) out << "\t";
            } out << std::endl;
        }
    }

    template<typename T>
    void SerializationDecorator<T>::read(std::istream& in) {
        if (!_matrix) {
            return;
        }

        for (size_t i = 0; i < _matrix->getRows(); ++i) {
            for (size_t j = 0; j < _matrix->getCols(); ++j) {
                in >> _matrix(i, j);
            }
        }
    }
}

#endif // !MATRIX_SERIALIZATION_DECORATOR_CPP