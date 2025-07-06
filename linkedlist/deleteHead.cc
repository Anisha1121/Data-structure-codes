#include <iostream>
#include <vector>
using namespace std;

class Node {
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

// Function to delete the head of the linked list
Node* deleteHead(Node* head) {
    if (!head) return nullptr; // Handle case of an empty list
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

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
    cout << "Original linked list: ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Delete the head of the linked list
    head = deleteHead(head);

    // Print the linked list after deleting the head
    cout << "Linked list after deleting head: ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
