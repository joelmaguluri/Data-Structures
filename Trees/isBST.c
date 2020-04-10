#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

int isBST(int *prev, struct TreeNode *root)
{
    if (!root)
        return 1;
    isBST(prev, root->left);
    if (*prev != -1 && *prev > root->data)
        return 0;
    *prev = root->data;
    if (!isBST(prev, root->right))
        return 0;
    return 1;
}

void main()
{
    struct TreeNode *root = sampleBST();
    int prev = -1;
    printf("%d", isBST(&prev, root));
}