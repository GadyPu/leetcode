#include <stdlib.h>
#include <stdio.h>
void merge(int* nums1, int m, int* nums2, int n) {
    int *arr = (int *)malloc(sizeof(int) * (n + m));
    int i = 0, j = 0, k = 0;
    while(i < m && j < n) {
        if(nums1[i] < nums2[j]) {
            arr[k] = nums1[i++];
        } else {
            arr[k] = nums2[j++];
        }
        k++;
    }
    while(i < m) {
        arr[k++] = nums1[i++];
    }
    while(j < n) {
        arr[k++] = nums2[j++];
    }
    for(i = 0; i < k; i++) {
        nums1[i] = arr[i];
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
    int nums1[100] = { 3, 5, 7, 11, 23 };
    int nums2[4] = { 1, 4, 9, 13 };
    merge(nums1, 5, nums2, 4);
    show(nums1, 9);
    return 0;
}
