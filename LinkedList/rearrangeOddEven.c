#include "listADT.h"

struct ListNode *rearrangeEvenOdd(struct ListNode *head)
{

  struct ListNode *even_head = NULL, *odd_head = NULL, *t1, *t2, *t3;
  t1 = t2 = t3 = NULL;

  odd_head = head;        //setting odd head to the first element of the LL
  even_head = head->next; //setting even head to the second element of LL

  t1 = odd_head;
  if (t1 != NULL)
    t2 = even_head;
  if (t2 != NULL)
    t3 = even_head->next;
  while (t3 != NULL)
  {
    t1->next = t3;
    if (t3->next != NULL)
      t2->next = t3->next;
    if (t3->next != NULL)
    {
      t3 = t3->next->next;
    }
    else
    {
      t3 = NULL;
    }
    t1 = t1->next;
    t2 = t2->next;
  }
  t1->next = NULL;
  t2->next = NULL;

  t1 = odd_head;
  while (t1->next != NULL)
  {
    t1 = t1->next;
  }
  t1->next = even_head;
  return odd_head;
}

void main()
{
  struct ListNode *head = getSampleLL();
  head = head->next->next;
  head = rearrangeEvenOdd(head);
  traverse(head);
}
