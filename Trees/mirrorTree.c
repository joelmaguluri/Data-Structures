#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

void mirrorTree(struct TreeNode *root)
{
  if (root)
  {
    mirrorTree(root->left);
    mirrorTree(root->right);
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
  return;
}
void main()
{
  struct TreeNode *root = constructBinaryTree(8);
  printf("Original Tree:\n");
  levelOrderTraversal(root);
  mirrorTree(root);
  printf("\nMirror Tree:\n");
  levelOrderTraversal(root);
}