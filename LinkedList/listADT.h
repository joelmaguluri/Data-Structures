#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int data;
  struct ListNode *next;
};

void traverse(struct ListNode *head)
{
  struct ListNode *temp = head;
  while (temp != NULL)
  {
    printf("%d\t", temp->data);
  }
}