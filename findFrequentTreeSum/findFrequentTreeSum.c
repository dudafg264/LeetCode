#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    if (node == NULL) exit(1);
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree() {
    int value;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &value);
    
    if (value == -1) return NULL;
    
    struct TreeNode* node = createNode(value);
    printf("Enter left child of %d:\n", value);
    node->left = buildTree();
    printf("Enter right child of %d:\n", value);
    node->right = buildTree();
    
    return node;
}

int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int calculateSums(struct TreeNode* node, int* sums, int* index) {
    if (!node) return 0;

    int leftSum = calculateSums(node->left, sums, index);
    int rightSum = calculateSums(node->right, sums, index);
    int sum = node->val + leftSum + rightSum;

    sums[(*index)++] = sum;
    return sum;
}

int compareInt(const void* a, const void* b) {
    int intA = *(const int*)a;
    int intB = *(const int*)b;
    return intA - intB;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int numNodes = countNodes(root);
    int* sums = (int*) malloc(numNodes * sizeof(int));
    int index = 0;

    calculateSums(root, sums, &index);

    qsort(sums, numNodes, sizeof(int), compareInt);

    int maxFreq = 0, currentFreq = 1;
    for (int i = 1; i < numNodes; i++) {
        if (sums[i] == sums[i - 1]) {
            currentFreq++;
        } else {
            if (currentFreq > maxFreq) maxFreq = currentFreq;
            currentFreq = 1;
        }
    }
    if (currentFreq > maxFreq) maxFreq = currentFreq;

    int count = 0;
    currentFreq = 1;
    for (int i = 1; i < numNodes; i++) {
        if (sums[i] == sums[i - 1]) {
            currentFreq++;
        } else {
            if (currentFreq == maxFreq) count++;
            currentFreq = 1;
        }
    }
    if (currentFreq == maxFreq) count++;

    int* result = (int*) malloc(count * sizeof(int));
    int resultIndex = 0;

    currentFreq = 1;
    for (int i = 1; i < numNodes; i++) {
        if (sums[i] == sums[i - 1]) {
            currentFreq++;
        } else {
            if (currentFreq == maxFreq) result[resultIndex++] = sums[i - 1];
            currentFreq = 1;
        }
    }
    if (currentFreq == maxFreq) result[resultIndex++] = sums[numNodes - 1];

    *returnSize = count;
    free(sums);
    return result;
}

struct TreeNode* NewNode(int value) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }
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
    printf("Build your binary tree:\n");
    struct TreeNode* root = buildTree();
    
    int returnSize;
    int* result = findFrequentTreeSum(root, &returnSize);

    printf("Most frequent subtree sums: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);
    FreeTree(root);
    return 0;
}