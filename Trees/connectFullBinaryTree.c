#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

void connectFullBinaryTree(struct TreeNode *root)
{
  if (root)
  {
    struct TreeNode *temp = root;
    while (temp != NULL)
    {

      if (temp->left)
        temp->left->next = temp->right;
      if (temp->right && temp->next)
        temp->right->next = temp->next->left;
      temp = temp->next;
    }
    connectFullBinaryTree(root->left);
  }
}

void main()
{
  struct TreeNode *root = constructBinaryTree(10);
  connectFullBinaryTree(root);
  printConnections(root);
}