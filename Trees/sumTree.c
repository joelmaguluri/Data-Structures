#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

int sumTree(struct TreeNode*root)
{
    if(!root)//if root is null return 0
    {
        return 0;
    }
    int leftsum=sumTree(root->left);
    int rightsum=sumTree(root->right);
    root->data=root->data+leftsum+rightsum;
    return root->data;
}