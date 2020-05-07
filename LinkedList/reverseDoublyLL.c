#include "listADT.h"

struct DoublyLinkedListNode *reverse(struct DoublyLinkedListNode *head)
{
  struct DoublyLinkedListNode *prev = NULL, *curr = head, *next = NULL;
  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    curr->prev = next;
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
}