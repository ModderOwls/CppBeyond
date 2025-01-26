
#include "Inventory.h"

void Inventory::put(int item) 
{
    std::unique_lock<std::mutex> lock(mutex);

    items.push_back(item);

    //Notify thread.
    cv.notify_one();
}

bool Inventory::get(int& item) 
{
    std::unique_lock<std::mutex> lock(mutex);

    if (!items.empty()) 
    {
        item = items.back();
        items.pop_back();
        return true;
    }

    //Return false if the inventory is empty.
    return false;
}

void Inventory::render() 
{
    std::unique_lock<std::mutex> lock(mutex);

    //Render each item in inventory.
    for (int i = 0; i < items.size(); ++i) 
    {
        std::cout << items[i] << ", ";
    }

    //Render the item count in inventory.
    std::cout << std::endl << "Total items: " << items.size() << std::endl;
}

int Inventory::size() 
{
    std::unique_lock<std::mutex> lock(mutex);

    return items.size();
}