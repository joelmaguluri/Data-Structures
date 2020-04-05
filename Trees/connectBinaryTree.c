#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

struct TreeNode *getNext(struct TreeNode *root)
{
  if (!root)
    return NULL;
  if (root->left)
    return root->left;
  else if (root->right)
    return root->right;
  else
    return getNext(root->next);
}
struct TreeNode *connectBinaryTree(struct TreeNode *root)
{
  if (root)
  {
    struct TreeNode *temp = root;
    while (temp != NULL)
    {
      if (temp->left)
      {
        if (temp->right)
          temp->left->next = temp->right;
        else
        {
          temp->left->next = getNext(temp->next);
        }
      }
      if (temp->right)
      {
        temp->right->next = getNext(temp->next);
      }
      temp = temp->next;
    }
    connectBinaryTree(root->left);
  }
}
void printConnection(struct TreeNode *root)
{
  if (root)
  {
    struct TreeNode *temp = root;
    while (temp != NULL)
    {
      printf("%d", temp->data);
      temp = temp->next;
    }
    printf("\n");
    printConnections(root->left);
  }
}
void main()
{
  struct TreeNode *root = constructBinaryTree(7);
  connectBinaryTree(root);
  printConnection(root);
}