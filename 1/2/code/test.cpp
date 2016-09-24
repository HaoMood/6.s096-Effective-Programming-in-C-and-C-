/*
 * MIT 6.s096
 * Assignment 1 Problem 2 & 3
 * Hao Zhang
 * 2016.09.24
 * test.cpp
 */

#include <string>
using std::string;
using std::to_string;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;

#include <iostream>
using std::cerr;
using std::endl;

#include <cstdlib>

#include "Matrix.h"

#ifndef NDEBUG
using std::cout;
#endif

int main()
{
    for (int i = 1; i != 11; ++i) {
#ifndef NDEBUG
        cout << i << endl;
#endif

        const string file_in = "../matrix_data/matrix." + to_string(i) 
            + ".in";
        const string file_out_pred = "../matrix_data/matrix." 
            + to_string(i) + ".out.pred";

        ifstream fin(file_in);
        ofstream fout(file_out_pred);
        if (!fin) {
            cerr << "[ERROR] Open file " << file_in << " failed.";
            return -1;
        }
        if (!fout) {
            cerr << "[ERROR] Open file " << file_out_pred << " failed.";
            return -1;
        }

        Matrix A(fin);
        Matrix B(fin);
        Matrix C = dot(A, B);
        C.save(fout);

        const string file_out = "../matrix_data/matrix." + to_string(i) 
            + ".out";
        const string cmd = "diff " + file_out_pred + " " + file_out;
        system(cmd.c_str());
    }
    return 0;
}
