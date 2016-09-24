/*
 * MIT 6.s096
 * Assignment 1 Problem 1
 * Hao Zhang
 * 2016.09.24
 * main.cpp
 *
 * Reference: 
 * [1]. J. Lu. http://cenalulu.github.io/linux/about-denormalized-float-number/.
 */

#include <string>
using std::string;

#include <cstdlib>

#include <iostream>
using std::cout;
using std::endl;

#include "show_float.h"

int main()
{
    for (int i = 1; i != 8; ++i) {
        cout << i << endl;
        string file_in = "../floating.data/floating." 
            +  std::to_string(i) + ".in";
        string file_out_predict = "../floating.data/floating." 
            +  std::to_string(i) + ".out.predict";
        show_float(file_in, file_out_predict);

        string file_out = "../floating.data/floating." 
            +  std::to_string(i) + ".out";
        string cmd = "diff " + file_out_predict + " " + file_out;
        system(cmd.c_str());
    }
    return 0;
}


