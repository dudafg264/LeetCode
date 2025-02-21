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

bool checkTree(struct TreeNode* root) {
    int sum = root->right->val + root->left->val;
    if (sum == root->val) return true;
    else return false;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {

    struct TreeNode* root = NewNode(4);
    root->left = NewNode(1);
    root->right = NewNode(2);

    bool result = checkTree(root);

    if (result == 1) printf("True\n");
    if (result == 0) printf("False\n");

    freeTree(root);

    return 0;
}