#include "listADT.h"

struct ListNode *reverseLL(struct ListNode *head)
{
  struct ListNode *p = NULL, *q = NULL, *r = NULL;
  if (head != NULL)
    p = head;
  else
    return head;
  q = p->next;
  p->next = NULL;
  if (q != NULL)
  {
    r = q->next;
  }
  while (q != NULL)
  {
    q->next = p;
    p = q;
    q = r;
    if (r != NULL)
      r = r->next;
  }
  return p;
}

void main()
{
  struct ListNode *head = createLinkedList(5);
  head = reverseLL(head);
  traverse(head);
}