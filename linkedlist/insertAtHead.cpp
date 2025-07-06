#include <iostream>
using namespace std;

class Node // linked list node
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
class LinkedList // linked list class
{
public:
  Node *head;  // head pointer
  Node *tail;  // tail pointer
  int size;    // size of the linked list
  LinkedList() // constructor to initialize head
  {
    head = tail = NULL;
    size = 0;
  }
  void insertAtHead(int val)
  {
    Node *temp = new Node(val);
    if (size == 0) // if the list is empty
    {
      head = tail = temp; // set head and tail to the new node
    }
    else // if the list is not empty
    {
      temp->next = head; // link the new node at the end
      head = temp;       // update the tail pointer
    }
    size++; // increment the size of the linked list
  }
  void display()
  {
    Node *temp = head;   // start from the head
    while (temp != NULL) // traverse until the end
    {
      cout << temp->val << " "; // print the value of the node
      temp = temp->next;        // move to the next node
    }
    cout << endl; // print a new line at the end
  }
};
int main()
{
  LinkedList ll;                                      // create a linked list object
  ll.insertAtHead(10);                                // insert 10 at the head
  ll.insertAtHead(20);                                // insert 20 at the head
  ll.insertAtHead(30);                                // insert 30 at the head
  ll.insertAtHead(40);                                // insert 40 at the head
  ll.display();                                       // display the linked list
  cout << "Size of linked list: " << ll.size << endl; // print the size of the linked list
  return 0;                                           // return 0 to indicate successful execution
}