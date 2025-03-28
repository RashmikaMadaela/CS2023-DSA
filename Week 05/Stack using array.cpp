#include <iostream>
using namespace std;

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
    Stack myStack(5);
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
        } else if (instruction == "isFull") {
            if (myStack.isFull()) std::cout << "True\n";
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