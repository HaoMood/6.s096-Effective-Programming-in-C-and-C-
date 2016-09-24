/*
 * MIT 6.s096
 * Getting startted Problem 10
 * Hao Zhang
 * 2016.09.24
 * test.cpp
 */

#include <cassert>

#include <vector>
using std::vector;

#include "search.h"

int main()
{
    vector<int> vec_data = {1, 2, 3, 4, 5};
    assert(search(vec_data, 1) == vec_data.begin());
    assert(search(vec_data, 4) == vec_data.begin() + 3);
    assert(search(vec_data, -1) == vec_data.end());


    assert(binary_search(vec_data, 1) == vec_data.begin());
    assert(binary_search(vec_data, 4) == vec_data.begin() + 3);
    assert(binary_search(vec_data, -1) == vec_data.end());
    return 0;
}
