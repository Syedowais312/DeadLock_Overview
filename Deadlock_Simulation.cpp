#include<bits/stdc++.h>
#include<thread>
#include<mutex>


using namespace std;
mutex acc1_mutex,acc2_mutex;
int acc1_balance=1000;
int acc2_balance=1000;

void transferAt0B()
{
    lock_guard<mutex> lock1(acc1_mutex);
    this_thread::sleep_for(chrono::milliseconds(50));
    lock_guard<mutex> lock2(acc2_mutex);

      acc1_balance -= 100;
    acc2_balance += 100;

    cout<<"transfer A  --> B done \n";
}

void transferBtoA()
{
    lock_guard<mutex> lock2(acc2_mutex);
    this_thread::sleep_for(chrono::milliseconds(50));
    lock_guard<mutex> lock2(acc1_mutex);

     acc1_balance -= 100;
    acc2_balance += 100;

    cout<<"Transfer B --> A done \n";
}

int main(){
    thread t1(transferAt0B);
    thread t2(transferBtoA);

    t1.join();
    t2.join();

    cout<<"Final Balance of Account 1: "<<endl<<acc1_mutex<<endl;
     cout<<"final Balance of Account 2: "<<endl<<acc2_mutex<<endl;

     return 0;
}