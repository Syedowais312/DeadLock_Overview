#include <iostream>
#include <thread>
#include <mutex>

std::mutex printerA;
std::mutex printerB;

void printDocument1() {
    std::lock_guard<std::mutex> lockA(printerA);
    std::cout << "Doc1: Using Printer A\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::lock_guard<std::mutex> lockB(printerB);
    std::cout << "Doc1: Using Printer B\n";
}

void printDocument2() {
    std::lock_guard<std::mutex> lockB(printerB);
    std::cout << "Doc2: Using Printer B\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::lock_guard<std::mutex> lockA(printerA);
    std::cout << "Doc2: Using Printer A\n";
}

int main() {
    std::thread t1(printDocument1);
    std::thread t2(printDocument2);

    t1.join();
    t2.join();
}
