#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void SortArray(std::vector<T>& array) 
{
    //Im assuming the assignment intends you to use this?
    //Haven't really found a way to code it manually.
    std::sort(array.begin(), array.end());
}