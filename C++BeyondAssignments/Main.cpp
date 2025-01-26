
#include <iostream>

#include "Inventory.h"


//Seperate from Inventory file to attach it to threads.
void addItems(Inventory& inventory, int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        inventory.put(i);
    }
}

int main()
{
    Inventory inventory;

    //Wrap reference to inventory for addItems and join threads.
    std::thread t1(addItems, std::ref(inventory), 0, 50);
    std::thread t2(addItems, std::ref(inventory), 50, 100);

    t1.join();
    t2.join();

    //Render the inventory content.
    inventory.render();

    //Now remove all items.
    int item;
    while (inventory.get(item)) 
    {
        std::cout << "Removed item: " << item << std::endl;
    }

    //Render inventory again after removing all items.
    inventory.render();

    return 0;
}