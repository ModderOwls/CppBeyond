#pragma once

#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>

//Inventory, just using int here for demonstration.
class Inventory {
private:
    std::vector<int> items;
    std::mutex mutex;
    std::condition_variable cv;

public:
    void put(int item);

    bool get(int& item);

    void render();

    int size();
};