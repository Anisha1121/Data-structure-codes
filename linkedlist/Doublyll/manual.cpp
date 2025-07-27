#include <iostream>
using namespace std;

class Node // linked list node
{
public:
  int val;
  Node *next;
  Node *prev;
  Node(int val)
  {
    this->val = val;
    this->next = NULL;
    this->prev = NULL;
  }
};
void display(Node *head)
{
  while (head != NULL)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
void displayReverse(Node *tail)
{
  while (tail != NULL)
  {
    cout << tail->val << " ";
    tail = tail->prev;
  }
  cout << endl;
}
int main()
{
  // 1 2 3 4 5
  Node *head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);
  Node *fourth = new Node(4);
  Node *fifth = new Node(5);

  head->next = second;
  second->prev = head;
  second->next = third;
  third->prev = second;
  third->next = fourth;
  fourth->prev = third;
  fourth->next = fifth;
  fifth->prev = fourth;

  display(head);
  displayReverse(fifth);
}
