/*
 * MIT 6.s096
 * Getting started Problem 8
 * Hao Zhang
 * 2016.09.23
 * is_prime.cpp
 */

#include <stdexcept>
using std::runtime_error;

#include <string>

#include "is_prime.h"

bool is_prime(int n)
{
    if (n <= 0) {
        throw runtime_error("n must be positive, where the input is " + 
                std::to_string(n));
    }

    if (n == 1) {
        return true;
    }
    
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
