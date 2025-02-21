#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* NewNode(int value) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    if (node == NULL)
        exit(1);

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bool evaluateTree(struct TreeNode* root) {
    if(root->left == NULL && root->right == NULL) return root->val == 1;
    
    bool valRight = evaluateTree(root->right);
    bool valLeft = evaluateTree(root->left);

    if(root->val == 2) return valLeft || valRight;
    if(root->val == 3) return valLeft && valRight;

    return false;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    bool result;

    struct TreeNode* root = NewNode(3);
    root->left = NewNode(2);
    root->right = NewNode(2);
    root->left->left = NewNode(1);
    root->left->right = NewNode(1);
    root->right->left = NewNode(1);
    root->right->right = NewNode(1);

    result = evaluateTree(root);

    printf("Result: %d\n", result);

    freeTree(root);

    return 0;
}