
# Tree Subtree Sums Frequency Finder

This program allows you to build a binary tree and calculates the most frequent subtree sums of the tree. The user is prompted to enter the values for each node of the tree, and the program will compute and output the most frequent sums of the subtrees in the tree.

## Features

- **Build a Binary Tree**: The program allows the user to input the values for the tree nodes. The value `1000` is treated as `NULL` to indicate an empty node (leaf).
- **Subtree Sum Calculation**: It calculates the sum of values for each subtree in the tree, including the sum of a node and its descendants.
- **Most Frequent Subtree Sums**: After calculating the subtree sums, the program finds and displays the most frequent sums in the tree.

## How It Works

1. **Build a Tree**:
   The program begins by prompting the user to input values for each node. The value `1000` is used to represent a `NULL` node (empty node). The program then recursively constructs the tree with the left and right children of each node.
   
2. **Calculate Subtree Sums**:
   The program computes the sum for each subtree by traversing the tree recursively. A sum is calculated for each node by adding the node’s value and the sums of its left and right children.
   
3. **Find Most Frequent Subtree Sums**:
   After calculating all subtree sums, the program sorts the sums and finds the most frequent ones, displaying them in ascending order.

## Notes

- The value `1000` is used to represent `NULL` in the tree, so be sure to input this value when prompted for an empty node.
- The program uses a recursive approach to build the tree and calculate the subtree sums.
- The most frequent subtree sums are computed based on the frequency of each sum in the entire tree.

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

### Test Cases

Here are three example test cases:

#### Test Case 1:
##### Input:
   ```c
    Build your binary tree:
    Enter node value (1000 for NULL): 5
    Enter left child of 5:
    Enter node value (1000 for NULL): 2
    Enter left child of 2:
    Enter node value (1000 for NULL): 1000
    Enter right child of 2:
    Enter node value (1000 for NULL): 1000
    Enter right child of 5:
    Enter node value (1000 for NULL): -3
    Enter left child of -3:
    Enter node value (1000 for NULL): 1000
    Enter right child of -3:
    Enter node value (1000 for NULL): 1000
   ```
##### Output:
   ```c
    Most frequent subtree sums: -3 2 4 
   ```

#### Test Case 2:
##### Input:
   ```c
    Build your binary tree:
    Enter node value (1000 for NULL): 5
    Enter left child of 5:
    Enter node value (1000 for NULL): 2 
    Enter left child of 2:
    Enter node value (1000 for NULL): 1000
    Enter right child of 2:
    Enter node value (1000 for NULL): 1000
    Enter right child of 5:
    Enter node value (1000 for NULL): -5
    Enter left child of -5:
    Enter node value (1000 for NULL): 1000
    Enter right child of -5:
    Enter node value (1000 for NULL): 1000
   ```
##### Output:
   ```c
    Most frequent subtree sums: 2 
  ```

#### Test Case 3:
##### Input:
   ```c
    Build your binary tree:
    Enter node value (1000 for NULL): 5
    Enter left child of 5:
    Enter node value (1000 for NULL): 2
    Enter left child of 2:
    Enter node value (1000 for NULL): 1
    Enter left child of 1:
    Enter node value (1000 for NULL): 1000
    Enter right child of 1:
    Enter node value (1000 for NULL): 1000
    Enter right child of 2:
    Enter node value (1000 for NULL): 1000
    Enter right child of 5:
    Enter node value (1000 for NULL): 1000
   ```
##### Output:
   ```c
    Most frequent subtree sums: 1 3 8 
   ```

### Conclusion
This program efficiently calculates and identifies the most frequent subtree sums in a binary tree using recursion and sorting.
