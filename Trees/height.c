// I/P:                  1
//                   2       3
//                4    5
//
// O/P: 2

#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

int height(struct TreeNode *root, int curentheight)
{
    if (!root)
        return curentheight - 1;
    int left_height = height(root->left, curentheight + 1);
    int right_height = height(root->right, curentheight + 1);
    if (left_height > right_height)
        return left_height;
    else
        return right_height;
}
void main()
{
    struct TreeNode *root = getSampleTree();
    printf("height of the tree is %d", height(root, 0)); // height of the root node is 0
}