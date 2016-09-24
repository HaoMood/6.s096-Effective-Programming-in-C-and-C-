/*
 * MIT 6.s096
 * Assignment 1 Problem 1
 * Hao Zhang
 * 2016.09.24
 * show_float.cpp
 */

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;

#include <stdexcept>
using std::runtime_error;

#include <algorithm>

#ifndef NDEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

#include "show_float.h"

string dec2bin(unsigned int dec) 
{
    string bin;
    for (int i = 0; i != 23; ++i) {
        bin += std::to_string(dec % 2);
        dec /= 2;
    }
    std::reverse(bin.begin(), bin.end());
    return bin;
}

void show_float(const string &file_in, const string &file_out)
{
#ifndef NDEBUG
    cerr << "[DEBUG] File: " << file_in << endl;       
#endif

    ifstream fin(file_in);
    ofstream fout(file_out);
    if (!fin) {
        throw runtime_error("[ERROR] Open file " + file_in + " failed.");
    }
    if (!fout) {
        throw runtime_error("[ERROR] Open file " + file_out + " failed.");
    }

    float val;
    fin >> val;

    while (fin >> val) {
        unsigned int *pval = reinterpret_cast<unsigned int *>(&val);

        unsigned int sign_mask = 1 << 31;
        unsigned int sign = (*pval & sign_mask) >> 31;
        unsigned int exponent_mask = ((1 << 8) - 1) << 23;
        int exponent = ((*pval & exponent_mask) >> 23) - 127;
        unsigned int mantissa_mask = (1 << 23) - 1;
        unsigned int mantissa = *pval & mantissa_mask;

        string output = "";
        if (sign == 1) {
            output += "-";
        }
        if (exponent == -126) {
            output += "0.";
        }
        else {
            output += "1.";
        }
        output += dec2bin(mantissa);
        output += " * 2^";
        output += std::to_string(exponent);

#ifndef NDEBUG
            cerr << "[DEBUG] val: " << val << endl;
            printf("[DEBUG] val: %x\n", *pval);
            printf("[DEBUG] sign: %x\n", sign);
            printf("[DEBUG] exponent: 0x%x\n", exponent);
            printf("[DEBUG] mantissa: 0x%x\n", mantissa);
            cerr << "[DEBUG] " << output << endl;
#endif

        fout << output << endl;
    }
}
