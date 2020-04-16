#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"
struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    int data;
    struct TreeNode *next;
};

struct DoublyLL
{
    int data;
    struct DoublyLL *left;
    struct DoublyLL *right;
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
    root->next = NULL;
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
            left->next = NULL;
            curr_node->left = left;
            enqueue(queue, left);
        }
        if (++value <= num)
        {
            struct TreeNode *right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            right->data = value;
            right->left = NULL;
            right->right = NULL;
            right->next = NULL;
            curr_node->right = right;
            enqueue(queue, right);
        }
    }
    return root;
}
void printConnections(struct TreeNode *root)
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

struct TreeNode *sampleBST()
{
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = 7;
    struct TreeNode *temp = root;
    temp->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp = temp->left;
    temp->data = 5;
    temp->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->right->data = 6;
    temp->right->left = NULL;
    temp->right->right = NULL;
    temp->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp = temp->left;
    temp->data = 4;
    temp->right = NULL;
    temp->left = NULL;
    temp = root;
    temp->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp = temp->right;
    temp->data = 9;
    temp->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->left->data = 8;
    temp->left->left = NULL;
    temp->left->right = NULL;
    temp->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp = temp->right;
    temp->data = 12;
    temp->left = NULL;
    temp->left = NULL;
    return root;
}

void inorderTraversal(struct TreeNode *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }
}

struct TreeNode *arrayToBST(struct TreeNode *root, int *arr, int start, int end)
{
    if (start <= end)
    {
        root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        int mid = (start + end) / 2;
        root->data = arr[mid];
        root->left = arrayToBST(root, arr, start, mid - 1);
        root->right = arrayToBST(root, arr, mid + 1, end);
        return root;
    }
    return NULL;
}