#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex printerA;
mutex printerB;

void printDocument1() {
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
    thread t1(printDocument1);
    thread t2(printDocument2);

    t1.join();
    t2.join();
}
