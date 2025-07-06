#include <iostream>
#include <vector>
using namespace std;

struct Node {
public:
    int val;
    Node* next;

    // Default Constructor
    Node() {
        val = 0;
        next = nullptr;
    }

    // Parameterized Constructor
    Node(int data) {
        val = data;
        next = nullptr;
    }
};

int main() {
    vector<int> arr{2, 5, 8, 3};

    // Create the head of the linked list
    Node* head = new Node(arr[0]);
    Node* temp = head;

    // Build the linked list
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    // Print the linked list
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }

}
