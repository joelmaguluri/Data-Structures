#include "listADT.h"

int findIntersection(struct ListNode *l1, struct ListNode *l2)
{
  int l1len = LLlength(l1); //finding length of l1
  int l2len = LLlength(l2); //finding length of l2
  int diff = 0;
  struct ListNode *temp = l1;
  struct ListNode *temp2 = l2;
  if (l1len > l2len)
  {
    diff = l1len - l2len; //2
    while (diff != 0)
    {
      diff--;
      temp = temp->next;
    }
  }
  else
  {
    diff = l2len - l1len;
    while (diff != 0)
    {
      temp2 = temp2->next;
      diff--;
    }
  }
  while (temp->data != temp2->data)
  {
    temp = temp->next;
    temp2 = temp2->next;
  }
  return temp->data;
}

void main()
{
  struct ListNode *l1 = getSampleLL();
  struct ListNode *l2 = NULL;
  struct ListNode *temp = l1, *temp2 = NULL;
  while (temp->data != 6)
  {
    temp = temp->next;
  }
  temp2 = l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
  l2->data = 44;
  temp2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp2->next->data = 55;
  temp2 = temp2->next;
  temp2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp2->next->data = 66;
  temp2 = temp2->next;
  temp2->next = temp;
  int intersectingvalue = findIntersection(l2, l1);
  printf("value %d", intersectingvalue);
}