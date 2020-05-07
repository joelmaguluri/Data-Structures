#include "listADT.h"
struct ListNode *MiddleElement(struct ListNode *head)
{
  struct ListNode *sp, *fp; // sp->slow pointer fp->fast Pointer
  sp = fp = head;           //setting both sp & fp to point to head
  if (sp->next == NULL)
    return head;                         // if single node return head
  while (fp != NULL && fp->next != NULL) //till fp is last node or fp points to null repeat the process
  {
    sp = sp->next;       // move slow pointer by one node
    fp = fp->next->next; // move fast  pointer by two node
  }
  return sp; // by the time the loop exit condition is met the slow pointer has the middle value
}
void reorderList(struct ListNode *head)
{
  struct ListNode *p = MiddleElement(head);
  struct ListNode *q = reverseLL(p->next);
  p->next = NULL;
  p = head;
  struct ListNode *p_next = NULL, *q_next = NULL;
  while (q != NULL)
  {
    p_next = p->next;
    q_next = q->next;
    p->next = q;
    q->next = p_next;
    p = p_next;
    q = q_next;
  }
}

void main()
{
  struct ListNode *head = getSampleLL();
  reorderList(head);

  traverse(head);
}
