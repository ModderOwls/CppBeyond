#include <queue>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

int counter = 0;
bool done = false;

std::queue<int> goods;

std::mutex mutex;
std::condition_variable cv;

void producer() 
{
    std::cout << "Starting producer..." << std::endl;

    for (int i = 0; i < 500; ++i) 
    {
        //Add one goodie and one to the counter, then notify consumer.
        std::unique_lock<std::mutex> lock(mutex);
        goods.push(i);
        counter++;
        cv.notify_one();
    }

    //Notify again, now with done being true.
    std::unique_lock<std::mutex> lock(mutex);
    done = true;
    cv.notify_one();

    std::cout << "Finished producer..." << std::endl;
}

void consumer() 
{
    std::cout << "Starting consumer..." << std::endl;

    while (true) 
    {
        //Wait for notification from producer and continue if either goods aren't empty or its done
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [] { return !goods.empty() || done; });
        
        //Empty goods and the counter.
        while (!goods.empty()) 
        {
            goods.pop();
            counter--;
        }

        //Check if both there are no more goods left and the producer is done, if so exit loop.
        if (done && goods.empty()) break;
    }

    std::cout << "Finished consumer..." << std::endl;
}

int main() 
{
    counter = 0;
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << std::endl;
}
