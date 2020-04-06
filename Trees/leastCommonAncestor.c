#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

struct TreeNode *leastCommonAncestor(struct TreeNode *root, int leftval, int rightval)
{
  if (!root)
    return NULL;
  if (root->data == leftval || root->data == rightval)
  {
    return root;
  }
  struct TreeNode *left = leastCommonAncestor(root->left, leftval, rightval);
  struct TreeNode *right = leastCommonAncestor(root->right, leftval, rightval);
  if (left && right)
  {
    return root;
  }
  else if (left && !right)
  {
    return left;
  }
  else if (right && !left)
  {
    return right;
  }
  else
  {
    return NULL;
  }
}

void main()
{
  struct TreeNode *root = constructBinaryTree(10);
  printf("Least common ancestor of 2 and 7 is %d", leastCommonAncestor(root, 8, 5)->data);
}