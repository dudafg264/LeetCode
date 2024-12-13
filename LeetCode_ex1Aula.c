#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **array, count = 0, i = 0;

    if ((array = (int**) malloc(numRows * sizeof(int))) == NULL){
        printf("We weren't able to allocate correctly.\n");
        exit(1);
    }

    else {
        for (int count = 0; count < numRows; count++) {
            if ((array[count] = (int*) malloc(count + 1 * sizeof(int))) == NULL){
                printf("We weren't able to allocate correctly.\n");
                break;
            }

            array[count][0] = 1;
            array[count][count] = 1;

            for (i = 1; i < count; i++) {
                array[count][i] = array[count - 1][i - 1] + array[count - 1][i];
            }
        }
            
        *returnSize = numRows;
        *returnColumnSizes = (int*) malloc(numRows * sizeof(int));
        for (int i = 0; i < numRows; i++) {
            (*returnColumnSizes)[i] = i + 1; // Cada linha tem 'i + 1' elementos
        }

        return array;
        }
}


int main(){
    int row, *returnColumnSizes, returnSize;

    
    printf("Type the number of the row you desire: ");
    scanf("%d", &row);
    
    int** result = generate(row, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}
