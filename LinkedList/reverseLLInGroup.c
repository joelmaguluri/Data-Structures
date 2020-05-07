#include "listADT.h"

struct ListNode *reverseLLInGroup(struct ListNode *head, int k)
{
  struct ListNode *temp_head = head, *prev = NULL, *next = NULL;
  int count = 0;

  while (head != NULL && count < k)
  {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
    count++;
  }
  if (next != NULL)
  {
    temp_head->next = reverseLLInGroup(next, k);
  }
  return prev;
}
void main()
{
  struct ListNode *head = getSampleLL();
  head = reverseLLInGroup(head, 3);
  traverse(head);
}
