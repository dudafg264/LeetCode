#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) { 
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
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

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root1 = NewNode(3);
    root1->left = NewNode(2);
    root1->right = NewNode(5);
    root1->left->left = NewNode(1);

    struct TreeNode* root2 = NewNode(3);
    root2->left = NewNode(2);
    root2->right = NewNode(5);
    root2->left->left = NewNode(1);

    struct TreeNode* mergedTree = mergeTrees(root1, root2);

    printf("Árvore mesclada (pré-ordem): ");
    printTree(mergedTree);
    printf("\n");

    freeTree(mergedTree);

    return 0;
}
