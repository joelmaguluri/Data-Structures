// Replace BST node with values greater than node
#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

void replaceBinarySearchTreeNode(struct TreeNode *root, int *prev)
{
    if (!root)
        return;
    replaceBinarySearchTreeNode(root->right, prev);
    if (*prev != -1)
        *prev = *prev + root->data;
    else
        *prev = root->data;
    root->data = *prev;
    replaceBinarySearchTreeNode(root->left, prev);
}

void main()
{
    struct TreeNode *root = sampleBST();
    int prev = -1;
    replaceBinarySearchTreeNode(root, &prev);
    struct TreeNode *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    printf("final sum is %d\n", temp->data);
}