#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

int sumOfLeftLeaves(struct TreeNode *root)
{

  if (!root)
    return 0;
  int left = 0;
  if (root->left && root->left->left == NULL && root->left->right == NULL)
    left = root->left->data;
  else
    left = sumOfLeftLeaves(root->left);
  int right = sumOfLeftLeaves(root->right);
  return left + right;
}