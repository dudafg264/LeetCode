#include <stdio.h>
#include <stdlib.h>

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

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    if (preorderSize == 0) return NULL;
    
    struct TreeNode* root = NewNode(preorder[0]);
    struct TreeNode* current;

    for (int i = 1; i < preorderSize; i++) {
        current = root;

        while (1) {
            if (preorder[i] < current->val) {
                if (current->left == NULL) {
                    current->left = NewNode(preorder[i]);
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = NewNode(preorder[i]);
                    break;
                }
                current = current->right;
            }
        }
    }

    return root;
}

void printTree(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int preorder[] = {8, 5, 1, 7, 10, 12};
    int preorderSize = 6;

    struct TreeNode* root = bstFromPreorder(preorder, preorderSize);
    
    printTree(root);

    freeTree(root);

    return 0;
}
