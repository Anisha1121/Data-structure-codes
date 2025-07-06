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
  void insertAtIndex(int index, int val)
  {
    if (index < 0 || index > size)
      cout << "Invalid index" << endl; // invalid index
    else if (index == 0)               // insert at head
    {
      insertAtHead(val); // reuse insertAtHead for head insertion
    }
    else if (index == size) // insert at tail
    {
      insertAtEnd(val); // reuse insertAtEnd for tail insertion
    }
    else // insert in the middle
    {
      Node *t = new Node(val); // temporary node to traverse
      Node *temp = head;
      for (int i = 0; i < index - 1; i++) // traverse to the node before the index
        temp = temp->next;
      t->next = temp->next; // link the new node
      temp->next = t;       // link the previous node to the new node
      size++;
    }

    // increment the size of the linked list
  }

  void deleteHead()
  {
    if (size == 0) // if the list is empty
    {
      cout << "List is empty, cannot delete head." << endl;
      return;
    }
    head = head->next; // move head to the next node
    size--;            // decrement the size of the linked list
  }

  void deleteTail()
  {
    if (size == 0) // if the list is empty
    {
      cout << "List is empty, cannot delete tail." << endl;
      return;
    }
    else // if the list has more than one node
    {
      Node *temp = head;
      while (temp->next != tail) // traverse to the second last node
        temp = temp->next;
      temp->next = NULL; // unlink the last node
      tail = temp;       // update tail to the second last node
      size--;            // decrement the size of the linked list
    }
  }

  void deleteAtIndex(int index)
  {
    if (index < 0 || index >= size) // invalid index
    {
      cout << "Invalid index" << endl;
      return;
    }
    if (index == 0) // delete head
    {
      deleteHead(); // reuse deleteHead for head deletion
    }
    else if (index == size - 1) // delete tail
    {
      deleteTail(); // reuse deleteTail for tail deletion
    }
    else // delete in the middle
    {
      Node *temp = head;
      for (int i = 0; i < index - 1; i++) // traverse to the node before the index
        temp = temp->next;
      temp->next = temp->next->next; // unlink the node at index
      size--;                        // decrement the size of the linked list
    }
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
  LinkedList ll; // create a linked list object
  ll.insertAtHead(10);
  ll.display();
  ll.insertAtEnd(12);
  ll.display(); // insert 12 at the end
  ll.insertAtHead(20);
  ll.display(); // insert 20 at the head
  ll.insertAtHead(30);
  ll.display();            // insert 30 at the head
  ll.insertAtIndex(2, 70); // insert 70 at index 2
  ll.display();
  ll.deleteHead();
  ll.display();
  ll.insertAtEnd(56);
  ll.display();
  ll.insertAtIndex(3, 45); // insert 45 at index 3
  ll.display();
  ll.deleteTail(); // delete the tail node
  ll.display();
  ll.deleteAtIndex(3); // delete the node at index 1
  ll.display();
  cout << "Size of linked list: " << ll.size << endl; // print the size of the linked list
  return 0;                                           // return 0 to indicate successful execution
}