#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstToGst(struct TreeNode* root) {
    int sum = 0;
    struct TreeNode* current = root;
    struct TreeNode* stack[100];
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->right;
        }

        current = stack[top--];
        sum += current->val;
        current->val = sum;

        current = current->left;
    }

    return root;
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

void printTree(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

void FreeTree(struct TreeNode* root) {
    if (root == NULL) return;
    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = NewNode(3);
    root->left = NewNode(2);
    root->right = NewNode(5);
    root->left->left = NewNode(1);

    root = bstToGst(root);

    printTree(root);

    FreeTree(root);

    return 0;
}