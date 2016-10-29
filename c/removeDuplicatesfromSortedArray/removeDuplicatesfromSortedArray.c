#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
	int i, res = 1;
	if(!numsSize) return 0;
	for(i = 1; i < numsSize; i++) {
		if(nums[i] == nums[i - 1]) continue;
		else nums[res++] = nums[i];
	}
	return res;
}
void output(int *num, int numSize) {
	int i;
	for(i = 0; i < numSize; i++) {
		printf("%d ", num[i]);
	}
	putchar('\n');
}
int main() {
	int A[] = { 1, 2, 3, 4 };
	int B[] = { 1, 2, 3, 3, 4, 5, 5};	
	output(A, sizeof(A) / sizeof(int));
	output(B, sizeof(B) / sizeof(int));
	output(A, removeDuplicates(A, sizeof(A) / sizeof(int)));
	output(B, removeDuplicates(B, sizeof(B) / sizeof(int)));
	return 0;
}
