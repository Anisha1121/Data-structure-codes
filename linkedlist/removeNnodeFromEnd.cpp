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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // traverse fast to (n+1) steps
        for (int i = 1; i <= n + 1; i++)
        {
            if (fast == NULL)
                return head->next;
            fast = fast->next;
        }

        // move slow and fast at same pace
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // now the slow is exactly at left of the nth node from end
        slow->next = slow->next->next;
        return head;
    }
};