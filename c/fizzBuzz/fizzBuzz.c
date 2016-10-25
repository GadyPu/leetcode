#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char *buf[] = { "Fizz", "Buzz", "FizzBuzz" };
char** fizzBuzz(int n, int* returnSize) {
	char **res = NULL;
	int i, d = strlen(buf[2]) + 1;;
	if(!n) {
		*returnSize = 0;
		return res;
	}
	res = (char **)malloc(sizeof(char **) * n);
	for(i = 0; i < n; i++) {
		res[i] = (char *)malloc(sizeof(char *) * d);
		memset(res[i], 0, d);
	}
	for(i = 1; i <= n; i++) {
		int k = -1;
		if(i % 3 == 0 && i % 5 != 0) {
			k = 0;
		} else if(i % 5 == 0 && i % 3 != 0) {
			k = 1;
		} else if(i % 3 == 0 && i % 5 == 0) {
			k = 2;
		}
		if(k == -1) {
			sprintf(res[i - 1], "%d", i);
		} else {
			strcpy(res[i - 1], buf[k]);
		}
	}
	*returnSize = n;
	return res;
}
int main() {
	int i, n = 15, returnSize = 0;
	char **res = fizzBuzz(n, &returnSize);
	for(i = 0; i < n; i++) puts(res[i]);
	return 0;
}
