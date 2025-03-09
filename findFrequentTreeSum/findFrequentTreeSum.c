#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the structure of a tree node */
struct tree_node {
    int val;
    struct tree_node *left;
    struct tree_node *right;
};

/* Function to create a new node */
struct tree_node *create_node(int value) {
    struct tree_node *node = malloc(sizeof(struct tree_node));
    if (node == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to build the binary tree */
struct tree_node *build_tree() {
    int value;
    printf("Enter node value (1000 for NULL): ");
    scanf("%d", &value);

    if (value == 1000) {
        return NULL;
    }

    struct tree_node *node = create_node(value);
    printf("Enter left child of %d:\n", value);
    node->left = build_tree();
    printf("Enter right child of %d:\n", value);
    node->right = build_tree();

    return node;
}

/* Function to count the number of nodes in the tree */
int count_nodes(struct tree_node *root) {
    if (!root) {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

/* Function to calculate the sums of the subtrees */
int calculate_sums(struct tree_node *node, int *sums, int *index) {
    if (!node) {
        return 0;
    }

    int left_sum = calculate_sums(node->left, sums, index);
    int right_sum = calculate_sums(node->right, sums, index);
    int sum = node->val + left_sum + right_sum;

    sums[(*index)++] = sum;
    return sum;
}

/* Comparison function used to sort the sums */
int compare_int(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    return int_a - int_b;
}

/* Main function to find the most frequent subtree sums */
int *find_frequent_tree_sum(struct tree_node *root, int *return_size) {
    if (!root) {
        *return_size = 0;
        return NULL;
    }

    int num_nodes = count_nodes(root);
    int *sums = (int *)malloc(num_nodes * sizeof(int));
    int index = 0;

    calculate_sums(root, sums, &index);

    qsort(sums, num_nodes, sizeof(int), compare_int);

    int max_freq = 0, current_freq = 1;
    for (int i = 1; i < num_nodes; i++) {
        if (sums[i] == sums[i - 1]) {
            current_freq++;
        } else {
            if (current_freq > max_freq) {
                max_freq = current_freq;
            }
            current_freq = 1;
        }
    }
    if (current_freq > max_freq) {
        max_freq = current_freq;
    }

    int count = 0;
    current_freq = 1;
    for (int i = 1; i < num_nodes; i++) {
        if (sums[i] == sums[i - 1]) {
            current_freq++;
        } else {
            if (current_freq == max_freq) {
                count++;
            }
            current_freq = 1;
        }
    }
    if (current_freq == max_freq) {
        count++;
    }

    int *result = (int *)malloc(count * sizeof(int));
    int result_index = 0;

    current_freq = 1;
    for (int i = 1; i < num_nodes; i++) {
        if (sums[i] == sums[i - 1]) {
            current_freq++;
        } else {
            if (current_freq == max_freq) {
                result[result_index++] = sums[i - 1];
            }
            current_freq = 1;
        }
    }
    if (current_freq == max_freq) {
        result[result_index++] = sums[num_nodes - 1];
    }

    *return_size = count;
    free(sums);
    return result;
}

/* Function to free the memory of the tree */
void free_tree(struct tree_node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    printf("Build your binary tree:\n");
    struct tree_node *root = build_tree();

    int return_size;
    int *result = find_frequent_tree_sum(root, &return_size);

    printf("Most frequent subtree sums: ");
    for (int i = 0; i < return_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free_tree(root);
    return 0;
}
