
#include "Functions.h"

void splitArray(const std::vector<std::string>& array, std::vector<std::string>& split1, std::vector<std::string>& split2, std::string splitValue)
{
    //Split input into either split1 or split2 depending on the alphabet position of splitValue.
    std::partition_copy(array.begin(), array.end(), std::back_inserter(split1),
        std::back_inserter(split2), [](const std::string& s) { return s < "purple"; });
}

void arrayToUppercase(std::vector<std::string>& array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        //Changes every char in the string to upper from array[i].begin to array[i].end (so entire string here).
        std::transform(array[i].begin(), array[i].end(), array[i].begin(), ::toupper);
    }
}

void removeDuplicate(std::vector<std::string>& array)
{
    //Sorts and erases any that aren't unique.
    std::sort(array.begin(), array.end());
    array.erase(std::unique(array.begin(), array.end()), array.end());
}


void removeNegative(std::vector<double>& array)
{
    //Removes any negative numbers using a lambda.
    //Remove_if shift the negative numbers to the end, while erase actually removes them. 
    array.erase(std::remove_if(array.begin(), array.end(), [](double num) { return num < 0; }), array.end());
}

std::vector<bool> isOddOrEven(const std::vector<double>& array)
{
    std::vector<bool> result;
    result.resize(array.size());

    //Turns each double in the given double array into an int and calculates if its even.
    //Conversion to int is because decimals dont count to being odd/even.
    std::transform(array.begin(), array.end(), result.begin(), [](int n) { return n % 2 == 0; });

    return result;
}

std::vector<double> getSumAverageAndProduct(const std::vector<double>& array)
{
    if (array.size() == 0)
    {
        return { 0, 0, 0 };
    }

    //Im not sure if numeric's accumulate is allowed, as it's not from algorithm/functional, 
    //but im assuming so as it's the only thing i saw in cplusplus.com that fit the bill.
    //Alternatively I can just use a for loop for sum and product.
    double sum = std::accumulate(array.begin(), array.end(), 0);
    double average = sum / array.size();
    double product = std::accumulate(array.begin(), array.end(), 1, std::multiplies<double>());

    return { sum, average, product };
}