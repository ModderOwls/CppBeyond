
#include <iostream>
#include <vector>
#include <functional>

#include "Functions.h"

int main() {
    //Create arrays.
    const std::vector<std::string> colours = {"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
    const std::vector<double> numbers = { 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

    //-----------------Colours-----------------
    for (int i = 0; i < colours.size(); ++i) std::cout << colours[i] << ", ";


    // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    std::cout << std::endl << "Split at purple 1: ";

    std::vector<std::string> coloursSplit1;
    std::vector<std::string> coloursSplit2;
    splitArray(colours, coloursSplit1, coloursSplit2, "purple");

    for (int i = 0; i < coloursSplit1.size(); ++i) std::cout << coloursSplit1[i] << ", ";
    std::cout << std::endl << "Split at purple 2: ";
    for (int i = 0; i < coloursSplit2.size(); ++i) std::cout << coloursSplit2[i] << ", ";


    // 2) alle elementen UPPERCASE te maken.
    std::cout << std::endl << "All uppercase: ";

    std::vector<std::string> coloursUppercase = colours;
    arrayToUppercase(coloursUppercase);
    for (int i = 0; i < coloursUppercase.size(); ++i) std::cout << coloursUppercase[i] << ", ";


    // 3) alle dubbele te verwijderen
    std::cout << std::endl << "No duplicates: ";

    std::vector<std::string> coloursNoDuplicates = colours;
    removeDuplicate(coloursNoDuplicates);
    for (int i = 0; i < coloursNoDuplicates.size(); ++i) std::cout << coloursNoDuplicates[i] << ", ";

    //-----------------Numbers-----------------
    std::cout << std::endl << std::endl;

    for (int i = 0; i < numbers.size(); ++i) std::cout << numbers[i] << ", ";


    // 1) alle negatieve elementen te verwijderen
    std::cout << std::endl << "No negative: ";

    std::vector<double> numbersNoNegative = numbers;
    removeNegative(numbersNoNegative);
    for (int i = 0; i < numbersNoNegative.size(); ++i) std::cout << numbersNoNegative[i] << ", ";
    

    // 2) voor alle elementen te bepalen of ze even of oneven zijn
    std::cout << std::endl << "Odd or even: ";

    std::vector<bool> numbersOddEven = isOddOrEven(numbers);
    for (int i = 0; i < numbersOddEven.size(); ++i) std::cout << (numbersOddEven[i] == true ? "Even" : "Odd") << ", ";


    // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
    std::cout << std::endl << "Sum, average, product: ";

    std::vector<double> numbersSumAverageProduct = getSumAverageAndProduct(numbers);
    for (int i = 0; i < numbersSumAverageProduct.size(); ++i) std::cout << numbersSumAverageProduct[i] << ", ";

    std::cout << std::endl;

    return 0;
}