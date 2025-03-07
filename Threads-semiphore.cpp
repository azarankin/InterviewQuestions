#include <iostream>
#include <thread>
#include <semaphore>  // C++20
#include <chrono>

using namespace std;

std::binary_semaphore semaphore(1);

// Function simulating handling of interrupt 1
void ISR1() {
    cout << "ISR1: Waiting for semaphore..." << endl;
    semaphore.acquire();  // Waits to acquire the semaphore
    cout << "ISR1: Handling interrupt!" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulating processing
    cout << "ISR1: Releasing the semaphore." << endl;
    semaphore.release();  // Releases the semaphore
}

// Function simulating handling of interrupt 2 (nested)
void ISR2() {
    cout << "ISR2: Waiting for semaphore..." << endl;
    semaphore.acquire();  // Waits to acquire the semaphore
    cout << "ISR2: Handling interrupt!" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulating processing
    cout << "ISR2: Releasing the semaphore." << endl;
    semaphore.release();  // Releases the semaphore
}

int main_semaphore() {
    // Assuming these are actual hardware interrupts, we simulate them using threads
    std::thread t1(ISR1);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Simulating delay between interrupts
    std::thread t2(ISR2);

    // Wait for threads to complete (simulating interrupt handling)
    t1.join();
    t2.join();

    cout << "Program finished." << endl;
    return 0;
}
