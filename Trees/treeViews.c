#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"
void rightView(struct TreeNode *root, int level, int *max)
{
  if (root)
  {
    if (*max < level)
    {
      *max = level;
      printf("%d\n", root->data);
    }
    rightView(root->right, level + 1, max);
    rightView(root->left, level + 1, max);
  }
}
void leftView(struct TreeNode *root, int level, int *max)
{
  if (root)
  {
    if (*max < level)
    {
      *max = level;
      printf("%d\n", root->data);
    }
    leftView(root->left, level + 1, max);
    leftView(root->right, level + 1, max);
  }
}

void main()
{
  struct TreeNode *root = constructBinaryTree(16);
  printf("right View:\n");
  int max = -1;
  rightView(root, 0, &max);
  max = -1;
  printf("\nleft View:\n");
  leftView(root, 0, &max);
}