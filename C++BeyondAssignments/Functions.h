#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>

void splitArray(const std::vector<std::string>& array, std::vector<std::string>& split1, std::vector<std::string>& split2, std::string splitValue);

void arrayToUppercase(std::vector<std::string>& array);

void removeDuplicate(std::vector<std::string>& array);

void removeNegative(std::vector<double>& array);

std::vector<bool> isOddOrEven(const std::vector<double>& array);

std::vector<double> getSumAverageAndProduct(const std::vector<double>& array);