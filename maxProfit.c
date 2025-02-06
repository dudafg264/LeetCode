#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int* start = prices;
    int smallest = 10000, indicator_smallest, profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (smallest > *start) {
            smallest = *start;
            indicator_smallest = i;
        }
        else if (*(prices + i) - smallest > profit) {
            profit = *(prices + i) - smallest;
        }
        start++;
    }

    if (profit <= 0)
        return 0;
        
    return profit;
}

int main() {
    int n;

    printf("Type the number of prices you will put: ");
    scanf("%d", &n);

    int* start = malloc(n * sizeof(int));
    int* prices = start;
    if (start == NULL){
        exit(1);
    }

    printf("Now, type the prices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", start);
        start++;
    }
    printf("Profit: %d\n", maxProfit(prices, n));

    free(prices);
}