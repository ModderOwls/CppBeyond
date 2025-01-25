
#include <iostream>

#include "ArraySorting.h"
#include "QueueTemplate.h"

int main()
{
    //Create arrays for sorting.
    std::vector<std::string> stringArray = { "B", "X", "F", "R", "Abba", "A", "C", "A"};
    std::vector<float> floatArray = { 3.3, 6.5, 1.3, 7.3, 8.2, 9.54, 10.52, 6.4251, 34.4352, 3.3 };


    //Print string array before sorting.
    std::cout << "String array: ";
    for (int i = 0; i < stringArray.size(); ++i)
    {
        std::cout << stringArray[i] << ", ";
    };
    std::cout << std::endl;

    //Sort string array.
    SortArray(stringArray);

    //Print string array after sorting.
    std::cout << "String array sorted: ";
    for (int i = 0; i < stringArray.size(); ++i)
    {
        std::cout << stringArray[i] << ", ";
    };
    std::cout << std::endl << std::endl;


    //Print float array before sorting.
    std::cout << "Float array: ";
    for (int i = 0; i < floatArray.size(); ++i)
    {
        std::cout << floatArray[i] << ", ";
    };
    std::cout << std::endl;

    //Sort float array.
    SortArray(floatArray);

    //Print float array after sorting.
    std::cout << "Float array sorted: ";
    for (int i = 0; i < floatArray.size(); ++i)
    {
        std::cout << floatArray[i] << ", ";
    };
    std::cout << std::endl << std::endl;


    //Create queue using an int.
    Queue<int> intQueue;

    //Put in some ints.
    intQueue.put(15);
    intQueue.put(25);
    intQueue.put(18);

    //Gets and removes them.
    intQueue.get();
    intQueue.get();

    //Get final queue size.
    std::cout << "Size of queue: " << intQueue.size() << std::endl << std::endl;


    //Create queue using a string.
    Queue<std::string> stringQueue;

    //Put in some strings.
    stringQueue.put("Hubahaba");
    stringQueue.put("Walada");
    stringQueue.put("Yabadaba doo");

    //Gets and removes them.
    stringQueue.get();
    stringQueue.get();
    stringQueue.get();

    //Get final queue size.
    std::cout << "Size of queue: " << stringQueue.size() << std::endl;
}
