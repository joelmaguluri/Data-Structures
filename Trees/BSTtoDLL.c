#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

void convertBSTToDLL(struct TreeNode *root, struct TreeNode **prev)
{
  if (root == NULL)
  {
    return NULL;
  }
  convertBSTToDLL(root->left, prev);
  if ((*prev) == NULL)
  {
    root->left = NULL;
  }
  else
  {
    (*prev)->right = root;
    root->left = *(prev);
  }
  (*prev) = root;
  convertBSTToDLL(root->right, prev);
}
void main()
{
  struct TreeNode *root = NULL, *temp = NULL, *prev = NULL;
  int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  root = arrayToBST(root, arr, 0, 8);
  convertBSTToDLL(root, &prev);
  temp = root;
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  printf("converted Doubly LL is \n");
  while (temp != NULL)
  {
    printf("%d\t", temp->data);
    temp = temp->right;
  }
}