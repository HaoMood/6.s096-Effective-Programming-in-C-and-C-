/*
 * MIT 6.s096
 * Getting started Problem 9
 * Hao Zhang
 * 2016.09.23
 * print_permutations.cpp
 */

#include <stdexcept>
using std::runtime_error;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#ifndef NDEBUG
using std::cerr;
#endif

#include "print_permutations.h"

void print(string prefix, vector<int> &vec_numbers)
{
#if 0
//#ifndef NDEBUG
    cerr << "[DEBUG] prefix = " << prefix << endl;
    cerr << "[DEBUG] vec_numbers = [";
    for (auto val: vec_numbers) {
        cerr << val << " ";
    }
    cerr << "]" << endl;
#endif

    if (vec_numbers.size() == 1) {
        cout << prefix << vec_numbers[0] << " ";
        return;
    }

    for (vector<int>::size_type i = 0; i != vec_numbers.size(); ++i) {
        string new_prefix = prefix + std::to_string(vec_numbers[i]);
        vector<int> others(vec_numbers);
        others.erase(others.begin() + i);
        print(new_prefix, others);
    }
}

void print_permutations(int n)
{
    if (n <= 0) {
        throw runtime_error("n must be positive, where the input is " + 
                std::to_string(n));
    }

    vector<int> vec_numbers;
    for (int i = 1; i != n + 1; ++i) {
        vec_numbers.push_back(i);
    }

    string prefix = "";
    print(prefix, vec_numbers);
    cout << endl;
}
