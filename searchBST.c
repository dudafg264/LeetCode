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

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if(root == NULL) return NULL;
    if (root->val == val) return root;
    struct TreeNode* leftSearch = searchBST(root->left, val);
    if (leftSearch != NULL) return leftSearch;
    return searchBST(root->right, val);
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
    root->left->right = NewNode(6);
    root->left->left = NewNode(8);

    struct TreeNode* result = searchBST(root, 1);

    if (result == NULL) {
        printf("Valor não encontrado na árvore.\n");
    } else {
        printf("[%d", result->val);
        
        if (result->left != NULL) {
            printf(", %d", result->left->val);
        } else {
            printf(", NULL");
        }

        if (result->right != NULL) {
            printf(", %d", result->right->val);
        } else {
            printf(", NULL");
        }
        printf("]\n");
    }

    freeTree(root);

    return 0;
}