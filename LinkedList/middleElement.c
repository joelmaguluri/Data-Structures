#include "listADT.h"

int findMiddleElement(struct ListNode *head)
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
  return sp->data;
}

void main()
{
  struct ListNode *head = createLinkedList(4);
  printf("Middle Element is %d", findMiddleElement(head));
}