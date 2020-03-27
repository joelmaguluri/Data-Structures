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