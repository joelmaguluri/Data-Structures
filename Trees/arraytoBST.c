#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

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

void main()
{
    int size;
    printf("Enter size of treen");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements in increasing order\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct TreeNode *root = NULL;
    root = arrayToBST(root, arr, 0, size - 1);
    inorderTraversal(root);
}
