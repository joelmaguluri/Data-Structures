#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"
#include <math.h>
void containsLevel(struct DoublyLL *list, struct TreeNode *root, int level)
{
  if (list->data == -1)
  {
    list->data = root->data;
    list->left = NULL;
    list->right = NULL;
  }
  else
  {
    int is_neg = level < 0 ? 1 : 0;
    int max_count = abs(level) - 1;
    int index = 0;
    struct DoublyLL *temp = list;
    if (is_neg)
    {
      while (index < max_count)
      {
        temp = temp->left;
        index++;
      }
      if (!temp->left)
      {
        temp->left = (struct DoublyLL *)malloc(sizeof(struct DoublyLL));
        temp->left->data = root->data;
        temp->left->right = temp;
        temp->left->left = NULL;
      }
    }
    else
    {
      while (index < max_count)
      {
        temp = temp->right;
        index++;
      }
      if (!temp->right)
      {
        temp->right = (struct DoublyLL *)malloc(sizeof(struct DoublyLL));
        temp->right->data = root->data;
        temp->right->left = temp;
        temp->right->right = NULL;
      }
    }
  }
}
void printVerticalSum(struct DoublyLL **list, struct TreeNode *root, int level)
{
  if (root)
  {
    containsLevel(*list, root, level);
    printVerticalSum(list, root->left, level - 1);
    printVerticalSum(list, root->right, level + 1);
  }
}
void main()
{
  struct TreeNode *root = constructBinaryTree(10);
  struct DoublyLL *list = (struct DoublyLL *)malloc(sizeof(struct DoublyLL));
  list->data = -1;
  printVerticalSum(&list, root, 0);
  struct DoublyLL *temp = list;
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  int sum = 0;
  while (temp != NULL)
  {
    printf("%d\t", temp->data);
    sum = sum + temp->data;
    temp = temp->right;
  }
  printf("\nVertical Sum is :%d\t", sum);
}