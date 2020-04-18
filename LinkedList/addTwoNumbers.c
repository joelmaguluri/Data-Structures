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
  temp->next = NULL;
  return head;
}
struct ListNode *getsecond()
{
  struct ListNode *temp = NULL;
  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = head;
  temp->val = 9;
  temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp = temp->next;
  temp->val = 9;
  temp->next = NULL;
  return head;
}
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  struct ListNode *temp1 = l1, *temp2 = l2, *curr1 = NULL, *curr2 = NULL;
  int carry = 0;
  while (temp1 != NULL && temp2 != NULL)
  {
    curr1 = temp1;
    curr2 = temp2;
    int sum = temp1->val + temp2->val + carry;
    carry = sum / 10;
    if (sum > 9)
    {
      temp1->val = sum % 10;
    }
    else
    {
      temp1->val = sum;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  if (temp1 != NULL && temp2 == NULL) // l1 is bigger length
  {
    while (carry && temp1 != NULL)
    {
      curr1 = temp1;
      int sum = temp1->val + carry;
      temp1->val = sum % 10;
      carry = sum / 10;
      temp1 = temp1->next;
    }
    if (carry)
    {
      curr1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
      curr1->next->val = carry;
      curr1->next->next = NULL;
    }
  }
  else if (temp1 == NULL && temp2 != NULL) //l2 is bigger length
  {
    curr1->next = temp2;
    while (carry && temp2 != NULL)
    {
      curr2 = temp2;
      int sum = temp2->val + carry;
      temp2->val = sum % 10;
      carry = sum / 10;
      temp2 = temp2->next;
    }
    if (carry)
    {
      curr2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
      curr2->next->val = carry;
      curr2->next->next = NULL;
    }
  }
  else // equal length lists
  {
    if (carry && curr1)
    {
      curr1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
      curr1->next->val = carry;
      curr1->next->next = NULL;
    }
  }

  return l1;
}

void main()
{
  struct ListNode *head1 = getfirst();
  struct ListNode *head2 = getsecond();
  struct ListNode *head = addTwoNumbers(head1, head2);
  while (head != NULL)
  {
    printf("%d", head->val);
    head = head->next;
  }
}
