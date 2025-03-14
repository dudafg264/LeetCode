#include <stdio.h>
#include <stdlib.h>

/* Function to calculate the maximum profit */
int MaxProfitAssignment(const int* difficulty, int difficulty_size, const int* profit, int profit_size, const int* worker, int worker_size) {
    int profit_r[worker_size];
    int sum = 0;

    for (int i = 0; i < worker_size; i++) {
        profit_r[i] = 0;
        for (int j = 0; j < difficulty_size; j++) {
            if (worker[i] >= difficulty[j] && profit_r[i] < profit[j]) {
                profit_r[i] = profit[j];
            }
        }
        sum += profit_r[i];
    }

    return sum;
}

/* Main function for input and execution */
int main() {
    int difficulty_size, worker_size;
    
    /* Input the number of jobs */
    printf("Enter the number of jobs: ");
    scanf("%d", &difficulty_size);
    
    int* difficulty = (int*)malloc(difficulty_size * sizeof(int));
    int* profit = (int*)malloc(difficulty_size * sizeof(int));
    
    printf("Enter the difficulty and profit for each job:\n");
    for (int i = 0; i < difficulty_size; i++) {
        scanf("%d %d", &difficulty[i], &profit[i]);
    }
    
    /* Input the number of workers */
    printf("Enter the number of workers: ");
    scanf("%d", &worker_size);
    
    int* worker = (int*)malloc(worker_size * sizeof(int));
    
    printf("Enter the capability of each worker:\n");
    for (int i = 0; i < worker_size; i++) {
        scanf("%d", &worker[i]);
    }
    
    /* Calculate the maximum profit */
    int max_profit = MaxProfitAssignment(difficulty, difficulty_size, profit, difficulty_size, worker, worker_size);

    printf("Maximum Profit: %d\n", max_profit);
    
    /* Free allocated memory */
    free(difficulty);
    free(profit);
    free(worker);
    
    return 0;
}
