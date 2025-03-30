#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize;  // Total subsets = 2^numsSize
    *returnSize = totalSubsets;
    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
    int** res = (int**)malloc(totalSubsets * sizeof(int*));

    for (int i = 0; i < totalSubsets; ++i) {
        int subsetSize = 0;
        for (int j = 0; j < numsSize; ++j) {
            if (i & (1 << j)) {
                subsetSize++;
            }
        }
        (*returnColumnSizes)[i] = subsetSize;
        res[i] = (int*)malloc(subsetSize * sizeof(int));
        int index = 0;
        for (int j = 0; j < numsSize; ++j) {
            if (i & (1 << j)) {
                res[i][index++] = nums[j];
            }
        }
    }
    return res;
}

void printSubsets(int** subsets, int returnSize, int* returnColumnSizes) {
    printf("[");
    for (int i = 0; i < returnSize; ++i) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d", subsets[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

int main() {
    int nums1[] = {1, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int* returnColumnSizes1;
    printf("Input: nums = [1,2,3]\n");
    int** result1 = subsets(nums1, numsSize1, &returnSize1, &returnColumnSizes1);
    printf("Output: ");
    printSubsets(result1, returnSize1, returnColumnSizes1);

    for (int i = 0; i < returnSize1; ++i) {
        free(result1[i]);
    }
    free(result1);
    free(returnColumnSizes1);

    int nums2[] = {0};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    int* returnColumnSizes2;
    printf("Input: nums = [0]\n");
    int** result2 = subsets(nums2, numsSize2, &returnSize2, &returnColumnSizes2);
    printf("Output: ");
    printSubsets(result2, returnSize2, returnColumnSizes2);

    for (int i = 0; i < returnSize2; ++i) {
        free(result2[i]);
    }
    free(result2);
    free(returnColumnSizes2);

    return 0;
}
