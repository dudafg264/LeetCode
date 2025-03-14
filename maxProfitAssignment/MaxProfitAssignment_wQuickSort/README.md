# Max Profit Assignment

This program calculates the maximum profit that can be earned by assigning jobs to workers based on their abilities, using a **QuickSort** algorithm to sort the jobs and workers. The program allows workers to complete jobs only if their ability is equal to or greater than the job's difficulty.

## How it Works

The program solves the problem by:

1. **Sorting**: Sorting the jobs by difficulty and the workers by their capabilities.
2. **Maximizing Profit**: For each worker, it assigns the most profitable job that the worker is capable of performing, considering jobs in ascending order of difficulty.
3. **Profit Calculation**: It then calculates the total maximum profit by accumulating the profits from the assigned jobs.

### Key Concepts

- **QuickSort**: The program uses the QuickSort algorithm to sort the job difficulties and worker abilities in ascending order. This helps efficiently match workers with the jobs they can perform.
- **Max Profit Calculation**: For each worker, the program finds the most profitable job they can complete and adds the profit to the total.

## Code Explanation

### `quicksort` Function

This function sorts an array in ascending order using the QuickSort algorithm, a divide-and-conquer sorting algorithm.

### `max` Function

This function returns the maximum of two integers. It's used to keep track of the highest profit that a worker can earn by performing a job.

### `maxProfitAssignment` Function

This function calculates the maximum total profit:
- It creates an array of jobs with their respective difficulties and profits.
- It sorts the jobs and workers using the `quicksort` function.
- It then assigns the most profitable job for each worker, accumulating the total profit.

### `main` Function

The `main` function:
1. Accepts job difficulty and profit values along with worker abilities.
2. Calls the `maxProfitAssignment` function to calculate the total maximum profit.
3. Outputs the result.

## Example

Input:
```c
int difficulty[] = {2, 4, 6, 8, 10};
int profit[] = {10, 20, 30, 40, 50};
int worker[] = {4, 5, 6, 7};
