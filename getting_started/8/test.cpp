/*
 * MIT 6.s096
 * Getting started Problem 8
 * Hao Zhang
 * 2016.09.23
 * test.cpp
 */

#include <cassert>

#include "is_prime.h"

int main()
{
    assert(is_prime(1) == true);
    assert(is_prime(2) == true);
    assert(is_prime(3) == true);
    assert(is_prime(4) == false);
    assert(is_prime(9) == false);
    assert(is_prime(11) == true);
    return 0;
}
