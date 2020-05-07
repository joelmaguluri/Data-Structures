#include <stdio.h>
#include <stdlib.h>

struct DoublyLinkedListNode
{
  int data;
  struct DoublyLinkedListNode *next;
  struct DoublyLinkedListNode *prev;
};
struct ListNode
{
  int data;
  struct ListNode *next;
};

int LLlength(struct ListNode *head)
{
  int len = 0;
  struct ListNode *temp;
  temp = head;
  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}

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

struct ListNode *getSampleLL()
{
  int i = 1;
  struct ListNode *head = NULL, *t2 = NULL, *t1 = NULL;
  while (i != 11)
  {
    struct ListNode *t2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    t2->data = i;
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
