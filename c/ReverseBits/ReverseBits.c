#include <stdio.h>
#define uint32_t unsigned int
uint32_t reverseBits(uint32_t n) {
    int m_16 = 0x0000ffff;
    int m_8  = 0x00ff00ff;
    int m_4  = 0x0f0f0f0f;
    int m_2  = 0x33333333;
    int m_1  = 0x55555555;
    int a = ((n & m_16) << 16) + ((n >> 16) & m_16);
    int b = ((a & m_8) << 8)   + ((a >> 8)  & m_8);
    int c = ((b & m_4) << 4)   + ((b >> 4)  & m_4);
    int d = ((c & m_2) << 2)   + ((c >> 2)  & m_2);
    int e = ((d & m_1) << 1)   + ((d >> 1)  & m_1);
    return e;
}
int main() {
    uint32_t a = 67;
    uint32_t b = reverseBits(a);
    printf("%u %u\n", a, reverseBits(b));
    return 0;
}
