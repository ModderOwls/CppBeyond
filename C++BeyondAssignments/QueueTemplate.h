#pragma once

#include <iostream>
#include <vector>

template<typename T>
class Queue 
{
public:
    Queue() { }

    //Adds an element at the end of the queue.
    void put(T element)
    {
        elements.push_back(element);

        //Print added element.
        std::cout << "Put at end element: " << element << std::endl;
    }

    //Get and remove first element.
    T get()
    {
        if (elements.size() == 0)
        {
            throw std::invalid_argument("Queue is empty.");
        }

        T firstElement = elements.front();
        elements.erase(elements.begin());

        //Print removed and remaining elements.
        std::cout << "Got and removed element: " << firstElement << ". Remaining: ";
        for (int i = 0; i < elements.size(); ++i)
        {
            std::cout << elements[i] << ", ";
        }
        std::cout << std::endl;

        return firstElement;
    }

    //Gets size of the queue.
    int size()
    {
        return elements.size();
    }

private:
    std::vector<T> elements;
};