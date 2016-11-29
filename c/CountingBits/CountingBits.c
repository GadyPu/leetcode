#include <stdlib.h>
#include <stdio.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int helper_1(int num) {
    int ans = 0;
    for(; num; ) {
        if(num & 1) ans++;
        num >>= 1;
    }
    return ans;
}
int helper(int a) {
    int m_1  = 0x55555555;
    int m_2  = 0x33333333;
    int m_4  = 0x0f0f0f0f;
    int m_8  = 0x00ff00ff;
    int m_16 = 0x0000ffff;
    int b = (a & m_1)  + ((a >> 1) & m_1);
    int c = (b & m_2)  + ((b >> 2) & m_2);
    int d = (c & m_4)  + ((c >> 4) & m_4);
    int e = (d & m_8)  + ((d >> 8) & m_8);
    int f = (e & m_16) + ((e >> 16) & m_16);
    return f;
}
int* countBits(int num, int* returnSize) {
    int i, *res = (int *)malloc(sizeof(int) * (num + 1));    
    for(i = 0; i <= num; i++) {
        res[i] = helper(i);
    }
    *returnSize = num + 1;
    return res;
}
int main() {
    int i, ret = 0, *res = countBits(5, &ret);
    for(i = 0; i < ret; i++) {
        printf("%d ", res[i]);
    }
    putchar('\n');
    return 0;
}
