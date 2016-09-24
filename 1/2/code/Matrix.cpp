/*
 * MIT 6.s096
 * Assignment 1 Problem 2 & 3
 * Hao Zhang
 * 2016.09.24
 * Matrix.cpp
 */

#include "Matrix.h"

using std::endl;

Matrix::Matrix(ifstream &in) 
{
    in >> _H >> _W;
    _content.reserve(_H * _W);
    int val;
    for (size_t i = 0; i != _H; ++i) {
        for (size_t j = 0; j != _W; ++j) {
            in >> val;
            _content.push_back(val);
        }
    }
}

void Matrix::save(ofstream &out) const
{
    out << _H << " " << _W << endl;
    for (size_t i = 0; i != _H; ++i) {
        for (size_t j = 0; j != _W; ++j) {
            if (j != 0) {
                out << " ";
            }
            out << at(i, j);
        }
        out << endl;
    }
}

Matrix dot(const Matrix &A, const Matrix &B)
{
    Matrix C(A.height(), B.width());
    if (A.width() != B.height()) {
        return C;
    }
    
    for (size_t i = 0; i != C.height(); ++i) {
        for (size_t j = 0; j != C.width(); ++j) {
            for (size_t k = 0; k != A.width(); ++k) {
                C.at(i, j) += A.at(i, k) * B.at(k, j);
            }
        }
    }
    return C;
}
