#include "listADT.h"

int kthNodeFromLast(struct ListNode *head, int k)
{
  struct ListNode *t1, *t2;
  int i = 0;
  t1 = t2 = head;
  while (i != k - 1)
  {
    t2 = t2->next;
    i++;
  }
  if (t2 == NULL)
    return -1;
  while (t2->next != NULL)
  {
    t1 = t1->next;
    t2 = t2->next;
  }
  return t1->data;
}
