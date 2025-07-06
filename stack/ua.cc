#include <iostream>
using namespace std;

class stimp {
    int stack[5];
    int top;

public:
    stimp() { top = -1; }  // Constructor to initialize top

    void push(int n) {
        if (top >= 4)  // Fix overflow condition
            cout << "Stack Overflow" << endl;
        else {
            top++;
            stack[top] = n;
            cout << "Pushed: " << n << endl;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;  // Return a default value
        } else {
            int popped_value = stack[top];
            top--;
            cout << "Popped: " << popped_value << endl;
            return popped_value;
        }
    }

    void display() {
        if (top == -1)
            cout << "Stack is empty." << endl;
        else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++)
                cout << stack[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    stimp s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  
    s.display();
    s.pop();
    s.pop();
    s.display();
    return 0;
}
