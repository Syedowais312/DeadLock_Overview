#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
// #include<bits/stdc++.h>
using namespace std;

mutex printA;
mutex printB;

void safePrint(const string& name){
    while(true){
        //try to loc printA
        if(printA.try_lock()){
          this_thread::sleep_for(chrono::milliseconds(10));
          //try to lock print B
            if(printB.try_lock()){
                cout<<name<<" printed successfully using A and B \n";

                printB.unlock();
                printA.unlock();
                break;
            }
            //if cannot lock print B
            else{
                printA.unlock();
                 this_thread::sleep_for(chrono::milliseconds(10));
            }
        }
    }
}

int main(){
    // OS scheduler decides randomly which thread runs first.
    thread t1(safePrint, "doc1");
    thread t2(safePrint, "doc2");

    t1.join();
    t2.join();
}