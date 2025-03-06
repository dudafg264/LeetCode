#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void reverse(struct TreeNode* left, struct TreeNode* right, int level) {
    if (!left || !right) return;
    else if (level % 2 != 0) {
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
    }

    reverse(left->left, right->right, level + 1);
    reverse(right->left, left->right, level + 1);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    int level = 0;

    if (!root) return 0;
    else reverse(root->left, root->right, 1);
    
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
    struct TreeNode* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right->left = NewNode(6);
    root->right->right = NewNode(7);

    printf("Árvore original: ");
    printTree(root);
    printf("\n");

    root = reverseOddLevels(root);

    printf("Árvore após inverter os níveis ímpares: ");
    printTree(root);
    printf("\n");

    FreeTree(root);

    return 0;
}
