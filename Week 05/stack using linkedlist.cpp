#include <iostream>

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
    Stack myStack;
    std::string instruction;

    while (true) {
        std::cin >> instruction;

        if (instruction == "push") {
            int data;
            std::cin >> data;
            myStack.push(data);
        } else if (instruction == "pop") {
            myStack.pop();
        } else if (instruction == "display") {
            myStack.display();
        } else if (instruction == "isEmpty") {
            if (myStack.isEmpty()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "stackTop") {
            std::cout << myStack.stackTop() << "\n";
        } else if (instruction == "exit") {
            break;
        } else {
            std::cout << "Invalid instruction. Valid instructions: push, pop, display, exit.\n";
        }
    }

    return 0;
}