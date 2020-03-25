#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    struct TreeNode*left;
    struct TreeNode*right;
    int data;
};

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