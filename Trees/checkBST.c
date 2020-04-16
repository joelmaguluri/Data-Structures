#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

int checkBST(struct TreeNode *root, int prev)
{
  if (!root)
    return NULL;
  checkBST(root->left, prev);
  if (prev != -1 && prev > root->data)
    return 0;
  prev = root->data;
  return checkBST(root->right, prev);
  return 1;
}