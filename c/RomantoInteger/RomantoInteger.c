#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define N (7)
const char symbol[N] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
const int  values[N] = { 1, 5, 10, 50, 100, 500, 1000 };
int digitToValue(char c) {
    int i;
    for(i = 0; i < N; i++) {
        if(c == symbol[i]) {
            return values[i];
        }
    }
    return 0;
}
int findMaxIndex(char str[], int lb, int ub) {
    int i, idx = lb, max = digitToValue(str[idx]);
    for(i = lb + 1; i <= ub; i++) {
        int d = digitToValue(str[i]);
        if(d > max) {
            max = d;
            idx = i;
        }
    }
    return idx;
}
int helper(char str[], int lb, int ub) {
    if(lb > ub) {
        return 0;
    } else if(lb == ub) {
        return digitToValue(str[lb]);
    } else {
        int i = findMaxIndex(str, lb, ub);
        return digitToValue(str[i]) - helper(str, lb, i - 1) + helper(str, i + 1, ub);
    }
}
int romanToInt(char* s) {
    int n = strlen(s);
    return helper(s, 0, n - 1);
}
int main() {
    printf("%d\n", romanToInt("MMXVI"));
    return 0;
}
