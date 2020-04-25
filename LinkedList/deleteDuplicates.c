#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *getsampleList()
{
  struct ListNode *temp = NULL;
  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = head;
  temp->val = 1;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 1;
  temp->next = NULL;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 1;
  temp->next = NULL;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 1;
  temp->next = NULL;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 1;
  temp->next = NULL;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 2;
  temp->next = NULL;
  return head;
}

struct ListNode *deleteDuplicates(struct ListNode *head)
{
  struct ListNode *curr = NULL, *temp_head = NULL, *r = NULL;
  if (head == NULL || head->next == NULL) // if there is a single node return it
    return head;

  temp_head = malloc(sizeof(struct ListNode)); // creating an empty node to keep track of the list
  r = temp_head;                               //r is temporary pointer which is used to add new nodes to the list
  r->next = NULL;

  curr = head; //curr is said to head and traversal beggins to remove the duplicates

  while (curr != NULL)
  {

    int flag = 0; // flag is a variable which is used to know if the previous and next values are same are not

    while (curr->next != NULL && curr->val == curr->next->val)
    {
      curr = curr->next;
      flag = 1;
    }

    if (flag == 1)
    {
      curr = curr->next;
      flag = 0;
    }
    else
    {
      r->next = curr;
      r = curr;
      curr = curr->next;
      r->next = NULL;
    }
  }

  return temp_head->next;
}

void main()
{
  struct ListNode *head = getsampleList();
  head = deleteDuplicates(head);
}