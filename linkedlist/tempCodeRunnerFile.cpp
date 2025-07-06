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