/*
 * MIT 6.s096
 * Getting startted Problem 10
 * Hao Zhang
 * 2016.09.24
 * search.h
 */

#ifndef SEARCH_H_
#define SEARCH_H_

#include <vector>
using std::vector;

vector<int>::iterator search(vector<int> &vec_data, int sought);

vector<int>::iterator binary_search(vector<int> &vec_data, int sought);

#endif
