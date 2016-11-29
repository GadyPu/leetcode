#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
bool isPowerOfTwo_1(int n) {
    if(!n) return false;
    while(!(n & 1)) {
        n >>= 1;
    }
    return n == 1;
}
bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    return !(n & (n - 1));
}
int main() {
    printf("%d\n", isPowerOfTwo(4));
    printf("%d\n", isPowerOfTwo(256));
    printf("%d\n", isPowerOfTwo(24));
    printf("%d\n", isPowerOfTwo(1));
    return 0;
}
