#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

struct TreeNode *leastCommonAncestorBST(struct TreeNode *root, int left, int right)
{
  if (!root)
    return NULL;
  if (root->data == left || root->data == right)
  {
    return root;
  }

  if (left > root->data && right > root->data)
  {
    return leastCommonAncestorBST(root->right, left, right);
  }
  else if (left < root->data && right < root->data)
  {
    return leastCommonAncestorBST(root->left, left, right);
  }
  return root;
}
void main()
{
  int arr[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
  struct TreeNode *root = NULL;
  root = arrayToBST(root, arr, 0, 8);
  levelOrderTraversal(root);
  printf("Least common ancestor of 2 and 9 is %d", leastCommonAncestorBST(root, 2, 9)->data);
}
