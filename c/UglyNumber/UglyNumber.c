#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
bool isUgly(int num) {
    if(num <= 0) {
        return false;
    }
    while(num % 2 == 0) num /= 2;
    while(num % 3 == 0) num /= 3;
    while(num % 5 == 0) num /= 5;
    return num == 1;
}
int main() {
    printf("%d\n", isUgly(19));
    return 0;
}
