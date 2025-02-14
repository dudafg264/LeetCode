#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode* NewNode(int value) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    if (node == NULL)
        exit(1);

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void FreeTree(struct TreeNode* root) {
    if (root == NULL) return;
    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
}

int main() {
    bool response;
    struct TreeNode* root1 = NewNode(3);
    root1->left = NewNode(2);
    root1->right = NewNode(5);
    root1->left->left = NewNode(1);

    struct TreeNode* root2 = NewNode(4);
    root2->left = NewNode(2);
    root2->right = NewNode(5);
    root2->left->left = NewNode(1);

    response = isSameTree(root1, root2);

    if(response == true)
        printf("The trees are the same.\n");
    else
        printf("The trees are different.\n");

    FreeTree(root1);
    FreeTree(root2);

    return 0;
}