/*
 * MIT 6.s096
 * Assignment 1 Problem 4
 * Hao Zhang
 * 2016.09.24
 * encrypt.cpp
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

#include "encrypt.h"

string convert(const string &str)
{
    if (str.size() == 1 || str.size() == 2) {
        return str;
    }

    string::size_type k = str.size() / 2;
    string sub1 = str.substr(0, k);
    string sub2 = str.substr(k, str.size() - k);
    std::reverse(sub1.begin(), sub1.end());
    std::reverse(sub2.begin(), sub2.end());
#ifndef NDEBUG
    cerr << "[DEBUG] sub1 = " << sub1 << endl;
    cerr << "[DEBUG] sub2 = " << sub2 << endl;
#endif

    return convert(sub1) + convert(sub2);
}

void encrypt(const string &file_in, const string &file_out)
{
    ifstream fin(file_in);
    ofstream fout(file_out);
    if (!fin) {
        throw runtime_error("[ERROR] Cannot open " + file_in);
    }
    if (!fout) {
        throw runtime_error("[ERROR] Cannot open " + file_out);
    }

    string str;
    string line;
    while (getline(fin, line)) {
        str += line;
        str += "\n";
    }

    string encrypted_str = convert(str.substr(0, str.size() - 1));
    fout << encrypted_str.size() << endl;
    fout << encrypted_str << endl;

#ifndef NDEBUG
    cerr << "[DEBUG] str = " << str << endl;
    cerr << "[DEBUG] encrypted_str = " << encrypted_str << endl;
#endif
}
