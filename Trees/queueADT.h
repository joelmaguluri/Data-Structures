#include <stdlib.h>
typedef struct queuenode
{
  struct TreeNode *node;
  struct queuenode *next;
} QueueNode;

typedef struct queue
{
  int size;
  QueueNode *top;
  QueueNode *recentnode;
} Queue;

void enqueue(Queue *queue, struct TreeNode *root)
{
  QueueNode *curr_node = (QueueNode *)malloc(sizeof(QueueNode));
  if (!queue->size)
  {
    curr_node->node = root;
    curr_node->next = NULL;
    queue->top = curr_node;
    queue->recentnode = queue->top;
  }
  else
  {
    curr_node->node = root;
    queue->recentnode->next = curr_node;
    curr_node->next = NULL;
    queue->recentnode = curr_node;
  }
  queue->size++;
}

QueueNode *dequeue(Queue *queue)
{
  if (!queue->size)
  {
    return NULL;
  }
  else
  {
    QueueNode *curr_node = queue->top;
    queue->top = queue->top->next;
    curr_node->next = NULL;
    queue->size--;
    if (!queue->size)
      queue->recentnode = NULL;
    return curr_node;
  }
}
