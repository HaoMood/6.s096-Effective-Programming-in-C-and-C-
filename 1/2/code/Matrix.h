/*
 * MIT 6.s096
 * Assignment 1 Problem 2 & 3
 * Hao Zhang
 * 2016.09.24
 * Matrix.h
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstddef>

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

class Matrix
{
private:
    size_t _H = 0;
    size_t _W = 0;
    vector<int> _content = {};

public:
    Matrix() = default;
    Matrix(const size_t H, const size_t W): 
        _H(H), _W(W), _content(vector<int>(H * W, 0)) {}
    Matrix(ifstream &in);

    int &at(const size_t i, const size_t j);
    int at(const size_t i, const size_t j) const;
    size_t height() const;
    size_t width() const;
    void save(ofstream &out) const;

    friend Matrix dot(const Matrix &A, const Matrix &B);
};

inline int &Matrix::at(const size_t i, const size_t j) 
{
    return _content[i * _W + j];
}

inline int Matrix::at(const size_t i, const size_t j) const
{
    return _content[i * _W + j];
}

inline size_t Matrix::height() const
{
    return _H;
}

inline size_t Matrix::width() const
{
    return _W;
}

#endif 
