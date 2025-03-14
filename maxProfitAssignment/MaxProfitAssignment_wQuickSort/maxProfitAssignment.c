#include <stdio.h>
#include <stdlib.h>

// QuickSort function for sorting integers
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pivotIndex = i + 1;
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

// Custom function to calculate max between two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Main function to calculate the maximum profit assignment
int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    // Create an array of jobs where each job is represented as {difficulty, profit}
    int jobs[difficultySize][2];
    for (int i = 0; i < difficultySize; i++) {
        jobs[i][0] = difficulty[i];  // difficulty
        jobs[i][1] = profit[i];      // profit
    }

    // Sort the difficulty and worker arrays
    quicksort(difficulty, 0, difficultySize - 1); // Sorting difficulties
    quicksort(worker, 0, workerSize - 1);          // Sorting workers

    int totalProfit = 0;
    int maxProfitForJob = 0;
    int jobIndex = 0;

    // Iterate through the workers and assign jobs
    for (int i = 0; i < workerSize; i++) {
        // Assign the most profitable job that the current worker can do
        while (jobIndex < difficultySize && jobs[jobIndex][0] <= worker[i]) {
            maxProfitForJob = max(maxProfitForJob, jobs[jobIndex][1]);
            jobIndex++;
        }
        totalProfit += maxProfitForJob;
    }

    return totalProfit;
}

int main() {
    int difficulty[] = {10, 20, 30, 40};
    int profit[] = {100, 200, 300, 400};
    int worker[] = {15, 25, 35, 45};

    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int profitSize = sizeof(profit) / sizeof(profit[0]);
    int workerSize = sizeof(worker) / sizeof(worker[0]);

    int result = maxProfitAssignment(difficulty, difficultySize, profit, profitSize, worker, workerSize);
    printf("Maximum Profit: %d\n", result);

    return 0;
}


