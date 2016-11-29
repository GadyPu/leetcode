#include <stdbool.h>
#include <stdio.h>
int missingNumber(int* nums, int numsSize) {
    int i, sum = numsSize * (numsSize + 1) / 2;
    for(i = 0; i < numsSize; i++) {
        sum -= nums[i];
    }
    return sum;
}
int main() {
    int nums[4] = { 0, 4, 3, 1 };
    printf("%d\n", missingNumber(nums, 4));
    return 0;
}
