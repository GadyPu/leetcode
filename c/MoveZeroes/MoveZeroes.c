#include <stdio.h>
void moveZeroes_1(int* nums, int numsSize) {
    int i, zero = 0;       
    for(i = 0; i < numsSize; i++) {
        if(nums[i]) {
            nums[i - zero] = nums[i];
        } else {
            zero++;
        }
    }
    for(i = 1; i <= zero; i++) {
        nums[numsSize - i] = 0;
    }
}
void moveZeroes(int *nums, int numsSize) {
    int i, j = 0;
    for(i = 0; i < numsSize; i++) {
        if(nums[i]) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}
void show(int *nums, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    putchar('\n');
}
int main() {
    int nums[] = { 6, 2, 5, 0, 6, 0, 9 };
    moveZeroes(nums, 7);
    show(nums, 7);
    return 0;
}
