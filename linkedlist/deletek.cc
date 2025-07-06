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

// Function to delete the kth element of the linked list
Node* deleteK(Node* head, int k) {
    if (head == nullptr) return head; // Handle case of an empty list
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp; // Use delete instead of free for C++
        return head;
    }

    int c = 1; // Start counter at 1
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && c < k) {
        prev = temp;
        temp = temp->next;
        c++;
    }

    if (temp != nullptr && prev != nullptr) {
        prev->next = temp->next;
        delete temp; // Use delete instead of free for C++
    }

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
    head = deleteK(head, 2);

    // Print the linked list after deleting the element
    cout << "Linked list after deleting the element: ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
