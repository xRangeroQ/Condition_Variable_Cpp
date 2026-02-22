// Include Libraries
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>
#include <condition_variable>

// Global Variables
std::string Data;
std::mutex Event_Lock;
std::condition_variable cv;
bool Process_Ready = false;
bool Process_Finished = false;

// Thread A
void Thread_A()
{
    // Wait Process
    std::unique_lock<std::mutex> Locker(Event_Lock);
    cv.wait(Locker, [] { return Process_Ready; });

    // Continue Process
    std::cout << "Process Continue!" << std::endl;
    Data += "Awesome!";

    // Perform Work
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Finish Process
    Process_Finished = true;
    std::cout << "Process Finished!" << std::endl;

    // Notify Main
    Locker.unlock();
    cv.notify_one();
}

// Main Thread
int main()
{
    // Create Thread
    std::thread Worker(Thread_A);

    // Create Data
    Data = "This Data ";

    // Notify Thread
    {
        std::lock_guard<std::mutex> Scope_Lock(Event_Lock);
        Process_Ready = true;
        std::cout << "Main is still waiting!" << std::endl;
    }
    cv.notify_one();

    // Wait Worker
    {
        std::unique_lock<std::mutex> Locker(Event_Lock);
        cv.wait(Locker, [] { return Process_Finished; });
    }
    std::cout << "Data Result = " << Data << std::endl;

    // Join Thread
    Worker.join();

    // Return Function
    return 0;
}
