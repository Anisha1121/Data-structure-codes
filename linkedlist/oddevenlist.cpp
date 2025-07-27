class Solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *odd = new ListNode(100);
    ListNode *even = new ListNode(200);
    ListNode *todd = odd;
    ListNode *teven = even;
    ListNode *temp = head;
    bool flag = true;

    while (temp)
    {
      if (flag)
      {
        todd->next = temp;
        todd = todd->next;
      }
      else
      {
        teven->next = temp;
        teven = teven->next;
      }
      temp = temp->next;
      flag = !flag;
    }

    // End even list and join lists
    teven->next = NULL;
    todd->next = even->next;

    odd = odd->next;
    even = even->next;

    return odd;
  }
};
