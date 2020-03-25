// I/P:                  1
//                   2       3
//                4    5   6   7
//                               9
// O/P: 3

#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

int height(struct TreeNode*root,int currrentheight)
{
    if(root)
        return currrentheight;
    int left_height=height(root->left,currrentheight+1);
    int right_height=height(root->right,currrentheight+1);
    if(left_height>right_height)
     return left_height;
    else 
     return right_height;
}