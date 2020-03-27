#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"
#include "queueADT.h"

void levelOrderTraversal(struct TreeNode *root)
{
  if (root)
  {
    Queue *queue = (Queue *)malloc(sizeof(Queue)); //creating a queue
    queue->size = 0;
    queue->top = NULL;
    enqueue(queue, root);
    while (queue->size) //while stack is not zero
    {
      QueueNode *curr_node = dequeue(queue);
      printf("%d\t", curr_node->node->data);
      if (curr_node->node->left)
        enqueue(queue, curr_node->node->left);
      if (curr_node->node->left)
        enqueue(queue, curr_node->node->right);
    }
  }

  else
  {

    printf("Unable to print as tree is empty");
  }
}

void main()
{
  struct TreeNode *root = getSampleTree();
  levelOrderTraversal(root);
}