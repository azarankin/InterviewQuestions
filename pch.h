#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

template <typename T>
using set = std::unordered_set<T>;

template <typename T1, typename T2>
using map = std::unordered_map<T1, T2>;

#define INT_MIN numeric_limits<int>::min()	//#include <limits.h>