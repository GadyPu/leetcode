#include <stdio.h>
int singleNumber(int* nums, int numsSize) {
    int i, res = nums[0];        
    for(i = 1; i < numsSize; i++) {
        res ^= nums[i];
    }
    return res;
}
int main() {
    int nums[5] = { 1, 5, 5, 1, 3 };
    printf("%d\n", singleNumber(nums, 5));
    return 0;
}
