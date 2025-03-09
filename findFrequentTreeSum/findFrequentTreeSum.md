# Tree Sum Frequency Calculator

This program calculates the most frequent subtree sums in a binary tree. A subtree sum is defined as the sum of all node values in a subtree, including the root node of the subtree.

### Problem Overview
Given a binary tree, the task is to compute the sum of all subtrees and find the most frequent subtree sums. Each node in the tree is a root of a subtree, and its value is included in the sum of that subtree. The program then identifies the most frequent sums among all the subtrees.

### Features
- **Build a Binary Tree**: The user can input node values to create a binary tree.
- **Subtree Sum Calculation**: For each node in the tree, it calculates the sum of values for all its descendants (including itself).
- **Frequency Calculation**: After calculating the sums, the program identifies the most frequent subtree sums.
- **Efficient Processing**: The program calculates sums using recursion and determines the most frequent sums efficiently using sorting and counting.

### Code Explanation

#### 1. **TreeNode Structure**
   The program uses a binary tree data structure, where each node is represented by a `TreeNode` struct:
   ```c
   struct TreeNode {
       int val;
       struct TreeNode* left;
       struct TreeNode* right;
   };
   ```

#### 2. **Functions**

- **`createNode(int value)`**: This function creates and returns a new node with a given value.
  
- **`buildTree()`**: This function builds the binary tree by recursively asking for user input. It builds the left and right subtrees for each node.

- **`countNodes(struct TreeNode* root)`**: This function counts the number of nodes in the binary tree by performing a post-order traversal.

- **`calculateSums(struct TreeNode* node, int* sums, int* index)`**: This function calculates the sum of each subtree and stores it in the `sums` array. It uses recursion to traverse the tree.

- **`compareInt(const void* a, const void* b)`**: A comparison function used for sorting the subtree sums in ascending order.

- **`findFrequentTreeSum(struct TreeNode* root, int* returnSize)`**: This is the main function that calculates the most frequent subtree sums. It first calculates all subtree sums, sorts them, and counts the frequencies to determine the most frequent sums.

- **`FreeTree(struct TreeNode* root)`**: A helper function to recursively free the memory allocated for the binary tree.

#### 3. **Main Function**
   - In the `main()` function, the user is prompted to build the binary tree.
   - Once the tree is built, the program calculates the most frequent subtree sums and prints them.
