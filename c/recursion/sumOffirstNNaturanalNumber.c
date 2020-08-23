#include <stdio.h>

int sum(int n){
    if (n>0){
        return sum(n-1) + n;
    }
    return 0;
}

int main() {
    int a = 100, r1 ,r2;
    r1 = sum(a);
    r2 = a*(a+1)/2;
    if (r1 == r2) {
        printf("True");
    }else{
        printf("False");
    }
    return 0;
}