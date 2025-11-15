#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex printerA;
mutex printerB;

void printDocument1() {
    // Thread 1 locks Printer A first
    lock_guard<mutex> lockA(printerA);
    cout << "Doc1: Using Printer A\n";

    // Sleep so that Thread 2 gets a chance to run and lock Printer B
    this_thread::sleep_for(chrono::milliseconds(50));

    // Now Thread 1 tries to lock Printer B,
    // but Printer B may already be locked by Thread 2 -> deadlock
    lock_guard<mutex> lockB(printerB);
    cout << "Doc1: Using Printer B\n";
}

void printDocument2() {
    // Thread 2 locks Printer B first
    lock_guard<mutex> lockB(printerB);
    cout << "Doc2: Using Printer B\n";

    // Sleep so that Thread 1 has a chance to lock Printer A
    this_thread::sleep_for(chrono::milliseconds(50));

    // Now Thread 2 tries to lock Printer A,
    // but Printer A may be locked by Thread 1 -> deadlock
    lock_guard<mutex> lockA(printerA);
    cout << "Doc2: Using Printer A\n";
}

int main() {
    // OS scheduler decides randomly which thread runs first.
    // If both threads lock different printers first, deadlock occurs.
    thread t1(printDocument1);
    thread t2(printDocument2);

    t1.join();
    t2.join();
}
