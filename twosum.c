#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, n;

    for (i = 0; i < numsSize; i++){
        for (n = i + 1; n < numsSize; n++){
            if (nums[i] + nums[n] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                if (result == NULL) {
                    printf("Error allocating memory");
                    exit(1);
                }
                result[0] = i;
                result[1] = n;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

int main(){
    int i, vector_size, *v, target_number, return_size, *result;

    printf("Please insert how many numbers you will be typing: ");
    scanf("%d", &vector_size);

    if ((v = (int *) malloc(vector_size * sizeof(int))) == NULL){
        printf("Error allocating memory");
        exit(1);
    }

    printf("Please insert the numbers on the vector:\n");
    for (i = 0; i < vector_size; i++){
        scanf("%d", &v[i]);
    }

    printf("Type the target number: ");
    scanf("%d", &target_number);

    result = twoSum(v, vector_size, target_number, &return_size);
    if (return_size == 2){
        printf("[%d, %d]", result[0], result[1]);
    }

    free(result);
    free(v);

    return 0;
}
