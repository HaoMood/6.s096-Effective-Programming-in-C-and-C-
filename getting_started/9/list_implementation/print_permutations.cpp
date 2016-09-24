/*
 * MIT 6.s096
 * Getting started Problem 9
 * Hao Zhang
 * 2016.09.23
 * print_permutations.cpp
 */

#include <stdexcept>
using std::runtime_error;

#include <list>
using std::list;

#include <string>
using std::string;

#include <algorithm>

#include <iostream>
using std::cout;
using std::endl;

#ifndef NDEBUG
using std::cerr;
#endif

#include "print_permutations.h"

void print(string prefix, list<int>::const_iterator begin, 
        list<int>::const_iterator end)
{
    if (begin == end) {
        cout << prefix << " ";
        return;
    }

    for (auto iter = begin; iter != end; ++iter) {
        string new_prefix = prefix + std::to_string(*iter);
        list<int> others(begin, end);
        auto pos = std::find(others.cbegin(), others.cend(), *iter);
        others.erase(pos);

#if 0
//#ifndef NDEBUG
        cerr << "[DEBUG] prefix = " << prefix << endl;
        cerr << "[DEBUG] others = [";
        for (auto out_iter = others.cbegin(); out_iter != others.cend(); 
            ++out_iter) {
            cerr << *out_iter << " ";
        }
        cerr << "]" << endl;
#endif

        print(new_prefix, others.cbegin(), others.cend());
    }
}

void print_permutations(int n)
{
    if (n <= 0) {
        throw runtime_error("n must be positive, where the input is " + 
                std::to_string(n));
    }

    list<int> list_numbers;
    for (int i = 1; i != n + 1; ++i) {
        list_numbers.push_back(i);
    }

    string prefix = "";
    print(prefix, list_numbers.cbegin(), list_numbers.cend());
    cout << endl;
}
