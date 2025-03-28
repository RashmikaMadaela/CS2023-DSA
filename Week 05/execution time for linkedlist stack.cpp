#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top; // Points to the top of the stack

public:
    Stack() { top = nullptr; }
    
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    int stackTop() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1; // Indicating empty stack
        }
        return top->data;
    }
    
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    auto start = high_resolution_clock::now();

    Stack myStack;
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