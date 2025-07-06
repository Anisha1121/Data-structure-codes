#include <iostream>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};

// Function to reverse the linked list
Node *rev(Node *head)
{
  Node *temp = head;
  Node *prev = NULL;
  Node *next;

  while (temp != NULL)
  {
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  return prev; // return new head
}

// Function to print linked list
void printList(Node *head)
{
  while (head != NULL)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  // Creating the linked list: 1 -> 2 -> 3 -> NULL
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);

  // Reverse and print
  Node *reversedHead = rev(head);
  printList(reversedHead); // Output: 3 2 1

  return 0;
}
