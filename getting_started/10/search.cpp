/*
 * MIT 6.s096
 * Getting startted Problem 10
 * Hao Zhang
 * 2016.09.24
 * search.cpp
 */

#include <algorithm>

#include "search.h"

vector<int>::iterator search(vector<int> &vec_data, int sought)
{
    auto iter = vec_data.begin();
    for (; iter != vec_data.end(); ++iter) {
        if (*iter == sought) {
            return iter;
        }
    }
    return iter;
}

vector<int>::iterator _binary_find(vector<int>::iterator begin, 
    vector<int>::iterator end, int sought)
{
    if (begin == end) {
        return end;
    }

    auto mid = begin + (end - begin) / 2;
    if (sought == *mid) {
        return mid;
    }
    else if (sought < *mid) {
        return _binary_find(begin, mid, sought);
    }
    else {
        return _binary_find(mid, end, sought);
    }
}

vector<int>::iterator binary_search(vector<int> &vec_data, int sought)
{
    if (!std::is_sorted(vec_data.cbegin(), vec_data.cend())) {
        std::sort(vec_data.begin(), vec_data.end());
    }

    if (vec_data.size() == 0) {
        return vec_data.end();
    }

    if (sought < vec_data[0] || sought > vec_data[vec_data.size() - 1]) {
        return vec_data.end();
    }

    return _binary_find(vec_data.begin(), vec_data.end(), sought);
}
