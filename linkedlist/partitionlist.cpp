#include <iostream>
using namespace std;

class ListNode // linked list ListNode
{
public:
  int val;
  ListNode *next;
  ListNode(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};
class Solution
{
public:
  ListNode *partition(ListNode *head, int x)
  {
    ListNode *lo = new ListNode(100);
    ListNode *hi = new ListNode(200);
    ListNode *tlo = lo;
    ListNode *thi = hi;
    ListNode *temp = head;
    while (temp != NULL)
    {
      if (temp->val < x)
      {
        tlo->next = temp;
        temp = temp->next;
        tlo = tlo->next;
      }
      else
      {
        thi->next = temp;
        temp = temp->next;
        thi = thi->next;
      }
    }

    tlo->next = hi->next;
    thi->next = NULL;

    lo = lo->next;
    hi = hi->next;

    return lo;
  }
};