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
  void insertAtEnd(int val)
  {
    Node *newNode = new Node(val);
    if (size == 0) // if the list is empty
    {
      head = tail = newNode; // set head and tail to the new node
    }
    else // if the list is not empty
    {
      tail->next = newNode; // link the new node at the end
      tail = newNode;       // update the tail pointer
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
  ll.insertAtEnd(10);                                 // insert 10 at the end
  ll.insertAtEnd(20);                                 // insert 20 at the end
  ll.insertAtEnd(30);                                 // insert 30 at the end
  ll.insertAtEnd(40);                                 // insert 40 at the end
  ll.display();                                       // display the linked list
  cout << "Size of linked list: " << ll.size << endl; // print the size of the linked list
  return 0;                                           // return 0 to indicate successful execution
}