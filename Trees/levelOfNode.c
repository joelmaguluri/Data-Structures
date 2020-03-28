#include <stdio.h>
#include <stdlib.h>
#include "treeADT.h"

int levelOfNode(int num, struct TreeNode *root, int level)
{
  if (root)
  {
    if (root->data == num)
    {
      return level;
    }
    int levelvalue = levelOfNode(num, root->left, level + 1);
    if (levelvalue != -1)
      return levelvalue;
    levelvalue = levelOfNode(num, root->right, level + 1);
    return levelvalue;
  }
  return -1;
}
void main()
{
  struct TreeNode *root = constructBinaryTree(8);
  int level = levelOfNode(8, root, 0);
  printf("level of 8 is\t%d", level);
}