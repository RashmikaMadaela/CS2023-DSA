#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Stack {
    public:
        int max;
        int top;
        int arr[1000];
    
        Stack(int size) {
            max = size;
            top = 0;
        }
    
        void push(int data) {
            if (top == max) {
                cout<<"Stack Overflow";
                return;
            }
            arr[top] = data;
            top++;
        }
    
        void pop() {
            if (top == 0) {
                cout<<"Stack Underflow";
                return;
            }
            top--;
        }
    
        void display() {
            if (top == 0) {
                return;
            }
            for (int i = top - 1; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    
        bool isEmpty() {
            return top == 0;
        }
    
        bool isFull() {
            return top == max;
        }
    
        int stackTop() {
            return arr[top - 1];
        }
            
};

int main() {

    auto start = high_resolution_clock::now();

    Stack myStack(9);
    std::string instruction;

    myStack.push(8);
    myStack.push(5);
    myStack.push(11);
    myStack.push(15);
    myStack.push(23);
    myStack.push(6);
    myStack.push(18);
    myStack.push(20);
    myStack.push(17);
    myStack.display();
    for (int i = 5; i > 0; i--) {
        myStack.pop();
    }
    myStack.display();
    myStack.push(4);
    myStack.push(30);
    myStack.push(3);
    myStack.push(1);
    myStack.display();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}