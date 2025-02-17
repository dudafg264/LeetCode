#include <stdio.h>
#include <stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int* returnPrices;

    returnPrices = (int*)malloc(sizeof(int) * pricesSize);
    if(returnPrices == NULL) exit(1);

    for(int i = 0; i < pricesSize; i++) {
        returnPrices[i] = prices[i];
        for(int j = i + 1; j < pricesSize; j++) {
            if(prices[i] >= prices[j]) {
                returnPrices[i] = prices[i] - prices[j];
                break; }
        }
    }
    
    *returnSize = pricesSize;

    return returnPrices;
}

int main() {
    int* prices;
    int pricesSize, returnSize;

    printf("Type how many prices you want to put in: ");
    scanf("%d", &pricesSize);

    if ((prices = (int*)malloc(sizeof(int) * pricesSize)) == NULL) exit(1);

    printf("Now, type the numbers: ");
    for(int i = 0; i < pricesSize; i++)
        scanf("%d", &prices[i]);
    
    int* result = finalPrices(prices, pricesSize, &returnSize);
    printf("Final prices are: ");
    for (int i = 0; i < returnSize; i++) 
        printf("%d ", result[i]);
    printf("\n");

    free(prices);
    free(result);
    
    return 0;
}