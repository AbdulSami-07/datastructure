#include <stdio.h>

int x = 0;

int fun(int n) {
    if(n>0) {
        x++;
        return fun(n-1) + x;
    }
    return 0;
}

int main() {
    int a=5, r;
    r = fun(a);
    printf("%d",r);
}