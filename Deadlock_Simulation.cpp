#include <iostream>
#include <thread>
#include <mutex>
Using namespace std;

 mutex printerA;
 mutex printerB;

void printDocument1() {
     lock_guard< mutex> lockA(printerA);
     cout << "Doc1: Using Printer A\n";
     this_thread::sleep_for( chrono::milliseconds(50));

     lock_guard< mutex> lockB(printerB);
     cout << "Doc1: Using Printer B\n";
}

void printDocument2() {
     lock_guard< mutex> lockB(printerB);
     cout << "Doc2: Using Printer B\n";
     this_thread::sleep_for( chrono::milliseconds(50));

     lock_guard< mutex> lockA(printerA);
     cout << "Doc2: Using Printer A\n";
}

int main() {
     thread t1(printDocument1);
     thread t2(printDocument2);

    t1.join();
    t2.join();
}
