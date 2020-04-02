#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"
struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    int data;
};
struct TreeNode *getSampleTree()
{
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = 1;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->data = 3;
    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;

    right->left = NULL;
    right->right = NULL;

    left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    left->left->data = 4;
    left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    left->right->data = 5;

    right = left->right;
    left = left->left;
    left->left = NULL;
    left->right = NULL;

    right->left = NULL;
    right->right = NULL;
    return root;
}
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
            if (curr_node->node->right)
                enqueue(queue, curr_node->node->right);
        }
    }

    else
    {

        printf("Unable to print as tree is empty");
    }
}
struct TreeNode *constructBinaryTree(int num)
{
    int value = 1;
    Queue *queue = (Queue *)malloc(sizeof(Queue)); //creating a queue
    queue->size = 0;
    queue->top = NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    enqueue(queue, root);
    while (queue->size) //while stack is not zero
    {
        struct TreeNode *curr_node = (dequeue(queue))->node;
        if (++value <= num)
        {
            struct TreeNode *left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            left->data = value;
            left->left = NULL;
            left->right = NULL;
            curr_node->left = left;
            enqueue(queue, left);
        }
        if (++value <= num)
        {
            struct TreeNode *right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            right->data = value;
            right->left = NULL;
            right->right = NULL;
            curr_node->right = right;
            enqueue(queue, right);
        }
    }
    return root;
}