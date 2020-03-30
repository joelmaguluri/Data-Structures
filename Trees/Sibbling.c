#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

void printSibblings(struct TreeNode *root, int value, int *status)
{

  if (root)
  {
    if (root->data == value)
    {
      printf("No Sibblings");
      return;
    }
    if (root->left && root->left->data == value)
    {
      if (root->right)
      {
        printf("Sibbling of Value %d  is %d ", value, root->right->data);
        *status = 1;
      }
    }
    else if (root->right && root->right->data == value)
    {
      if (root->left)
      {
        printf("Sibbling of Value %d  is %d ", value, root->left->data);
        *status = 1;
      }
    }
    else
    {
      printSibblings(root->left, value, status);
      if (!*status)
      {
        printSibblings(root->right, value, status);
      }
    }
  }
}

void main()
{
  struct TreeNode *root = constructBinaryTree(16);
  int status = 0;
  printSibblings(root, 16, &status);
  if (!status)
    printf("No Sibbling exists");
}
