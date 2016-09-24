/*
 * MIT 6.s096
 * Assignment 1 Problem 4
 * Hao Zhang
 * 2016.09.24
 * test.cpp
 */

#include <string>
using std::string;
using std::to_string;

#include <cstdlib>

#include "encrypt.h"

#ifndef NDEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

int main()
{
    for (int i = 1; i != 11; ++i) {
#ifndef NDEBUG
        cerr << i << endl;
#endif

        const string file_in = "../data/loop." + to_string(i) 
            + ".in";
        const string file_out_pred = "../data/loop." + to_string(i) 
            + ".out.pred";

        encrypt(file_in, file_out_pred);

        const string file_out = "../data/loop." + to_string(i) 
            + ".out";
        const string cmd = "diff " + file_out_pred + " " + file_out;
        system(cmd.c_str());
    }
    return 0;
}
