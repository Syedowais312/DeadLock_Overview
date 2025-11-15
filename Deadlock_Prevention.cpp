#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex printerA;
mutex printerB;

void printDocument1() {

   //locks both the mutex in the same order which prevent to deadlock
    lock_guard<mutex> lockA(printerA);
    lock_guard<mutex> lockB(printerB);

    cout << "Doc1 printed using A and B\n";
}

void printDocument2() {
    lock_guard<mutex> lockA(printerA);  // SAME ORDER
    lock_guard<mutex> lockB(printerB);

    cout << "Doc2 printed using A and B\n";
}

int main() {

     // OS scheduler decides randomly which thread runs first.
    thread t1(printDocument1);
    thread t2(printDocument2);

    t1.join();
    t2.join();
}
