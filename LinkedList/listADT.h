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
  printf("Traversing the list");
  while (temp != NULL)
  {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
}

struct ListNode *createLinkedList(int numofnodes)
{
  int i = 0;
  struct ListNode *head = NULL, *t1 = NULL, *t2 = NULL;

  while (i != numofnodes)
  {
    struct ListNode *t2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    scanf("%d", &t2->data);
    if (t1 == NULL && head == NULL)
    {
      head = t1 = t2;
    }
    else
    {
      t1->next = t2;
    }
    t1 = t2;
    t1->next = NULL;
    i++;
  }
  return head;
}