#include "listADT.h"

struct ListNode *MiddleElement(struct ListNode *head)
{
  struct ListNode *sp, *fp; // sp->slow pointer fp->fast Pointer
  sp = fp = head;           //setting both sp & fp to point to head
  if (sp->next == NULL)
    return head->data;                   // if single node return head
  while (fp != NULL && fp->next != NULL) //till fp is last node or fp points to null repeat the process
  {
    sp = sp->next;       // move slow pointer by one node
    fp = fp->next->next; // move fast  pointer by two node
  }
  return sp; // by the time the loop exit condition is met the slow pointer has the middle value
}
void reorderList(struct ListNode *head)
{
  struct ListNode *t1, *t2, *l1, *l2;
  l2 = MiddleElement(head)->next;
  if (l2->next = NULL)
  {
    t2 = head->next;
    t1 = head;
    t1->next = l2;
    l2->next = t2;
  }
  else
  {
    t1 = l2->next;
    t2 = t1->next;
    while (l2 != NULL && l2->next != NULL)
    {
      t1->next = l2;
      l2->next = t2;
      l2 = t2;
      if (l2 != NULL)
        t1 = l2->next;
      if (t1)
        t2 = t1->next;
    }
  }
}

1 2 3 4 5

    6 7 8 9