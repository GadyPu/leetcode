#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int helper(int num) {
    return !num ? 0 : num % 10 + helper(num / 10);
}
int addDigits(int num) {
    while(num >= 10) {
        num = helper(num);
    }
    return num;
}
int main() {
    printf("%d\n", addDigits(10));
    return 0;
}
