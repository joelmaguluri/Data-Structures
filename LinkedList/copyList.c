#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int val;
  struct TreeNode *next;
  struct TreeNode *random;
};

struct Node *copyRandomList(struct Node *head)
{
  if (head == NULL)
    return NULL;
  struct Node *connect, *temp;
  temp = head;
  while (temp != NULL)
  {
    connect = temp->next;
    temp->next = (struct Node *)(malloc(sizeof(struct Node)));
    struct Node *temp2 = temp->next;
    temp2->val = temp->val;
    temp2->next = connect;
    temp = connect;
    if (connect != NULL)
      connect = connect->next;
  }
  temp = head;
  connect = NULL;
  while (temp != NULL)
  {
    connect = temp->random;
    struct Node *temp2 = temp->next;
    if (connect != NULL)
      temp2->random = connect->next;
    else
      temp2->random = NULL;
    temp = temp2->next;
  }
  temp = head;
  struct Node *head2 = NULL, *temp2 = head->next;
  head2 = temp2;
  while (temp2->next != NULL)
  {
    temp->next = temp2->next;
    temp2->next = temp2->next->next;
    temp = temp->next;
    temp2 = temp2->next;
  }
  temp->next = NULL;
  return head2;
}
