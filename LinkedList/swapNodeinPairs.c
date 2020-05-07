#include "listADT.h"

struct ListNode *swapPairs(struct ListNode *head)
{
  struct ListNode *temp_head = head, *prev = NULL, *next = NULL;
  int count = 0;

  while (head != NULL && count < 2)
  {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
    count++;
  }
  if (next != NULL)
  {
    temp_head->next = swapPairs(next);
  }
  return prev;
}