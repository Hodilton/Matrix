#ifndef MATRIX_SERIALIZATION_DECORATOR_H
#define MATRIX_SERIALIZATION_DECORATOR_H

#include "../core/matrix_core.h"

#include <iostream>

namespace matrix::decorators {

    template <typename T>
    class SerializationDecorator {
    private:
        core::MatrixCore<T>* _matrix;

    public:
        SerializationDecorator();
        explicit SerializationDecorator(core::MatrixCore<T>& m);

    public:
        void print(std::ostream& out) const;
        void read(std::istream& in);
    };
}

#include "./serialization_decorator.cpp"

#endif // !MATRIX_SERIALIZATION_DECORATOR_H