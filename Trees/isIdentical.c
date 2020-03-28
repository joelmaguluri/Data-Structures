#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

int isIdentical(struct TreeNode *root1, struct TreeNode *root2)
{
  if (root1 && root2 || root1 == NULL && root2 == NULL)
  {
    if (root1 && root2)
    {
      if (root1->data != root2->data)
        return 0;
      int leftvalue = isIdentical(root1->left, root2->left);
      int rightvalue = isIdentical(root1->right, root2->right);
      if (leftvalue == rightvalue)
        return 1;
      else
        return 0;
    }
    return 1;
  }
  return 0;
}

void main()
{
  struct TreeNode *root1 = constructBinaryTree(8);
  struct TreeNode *root2 = constructBinaryTree(9);
  int flag = isIdentical(root1, root2);
  if (flag)
    printf("Both the tree are identical in structure and have same values");
  else
    printf("Both the trees are not Identical");
}