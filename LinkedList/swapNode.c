#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *getfirst()
{
  struct ListNode *temp = NULL;
  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = head;
  temp->val = 1;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 2;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 3;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 4;
  temp->next = NULL;
  return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *swapPairs(struct ListNode *head)
{
  if (!head)
    return head;                                               // if head is empty return head
  struct ListNode *temp1 = head, *temp2 = NULL, *temp3 = NULL; // set temp1 as head
  if (temp1 && temp1->next)
    temp2 = temp1->next; //set temp2 as next of temp1
  if (temp2 && temp2->next)
    temp3 = temp2->next; // set temp3 as net of temp2
  if (temp2)
  {
    temp2->next = temp1; //swapping the temp2 with temp1
    head = temp2;        // now temp2 becomes head and temp1 becomes next to head
  }
  else
    return temp1; // if there is no temp2 return temp1 or previous head
  temp1->next = swapPairs(temp3);
  return head;
}

void main()
{
  struct ListNode *head = getfirst();
  struct ListNode *temp = swapPairs(head);
  while (temp != NULL)
  {
    printf("%d", temp->val);
    temp = temp->next;
  }
}
