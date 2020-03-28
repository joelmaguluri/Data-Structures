#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

void deepestNode(struct TreeNode *root, int *maxlevel, int *curr_max, int current_level)
{
  if (root)
  {
    if (current_level >= *maxlevel)
    {
      *maxlevel = current_level;
      *curr_max = root->data;
    }
    deepestNode(root->left, maxlevel, curr_max, current_level + 1);
    deepestNode(root->right, maxlevel, curr_max, current_level + 1);
  }
}

void main()
{
  struct TreeNode *root = constructBinaryTree(8);
  int maxlevel = 0;
  int curr_max = root->data;
  deepestNode(root, &maxlevel, &curr_max, 0);
  printf("deepestNode is %d", curr_max);
}