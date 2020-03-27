#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

struct TreeNode *constructBinaryTree(int num)
{
  int arr[num], i;
  for (i = 0; i < num; i++)
  {
    arr[i] = i + 1;
  }
  i = 0;
  Queue *queue = (Queue *)malloc(sizeof(Queue)); //creating a queue
  queue->size = 0;
  queue->top = NULL;
  struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->data = arr[i];
  root->left = NULL;
  root->right = NULL;
  enqueue(queue, root);
  while (queue->size) //while stack is not zero
  {
    struct TreeNode *curr_node = (dequeue(queue))->node;
    if (++i < num)
    {
      struct TreeNode *left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      left->data = arr[i];
      left->left = NULL;
      left->right = NULL;
      curr_node->left = left;
      enqueue(queue, left);
    }
    if (++i < num)
    {
      struct TreeNode *right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      right->data = arr[i];
      right->left = NULL;
      right->right = NULL;
      curr_node->right = right;
      enqueue(queue, right);
    }
  }
  return root;
}
void main()
{
  int n;
  printf("Enter the last node of the tree\n");
  scanf("%d", &n);
  struct TreeNode *root = constructBinaryTree(n);
  levelOrderTraversal(root);
}
