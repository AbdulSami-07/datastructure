#include <stdio.h>

int pow_naive(int m , int n) {
    if (n == 0)
        return 1;
    else 
        return pow_naive(m,n-1) * m;
}

int pow_fast(int m , int n){
    if (n== 0)
        return 1;
    else if (n%2 == 0)
        return pow_fast(m*m,n/2);
    else 
        return m* pow_naive(m*m,(n-1)/2);
}

int main() {
    int m = 2 , n = 8;
    int r1 = pow_naive(m,n);
    int r2 = pow_fast(m,n);
    if(r1 == r2)
        printf("True : %d",r1);
    else 
        printf("False");

}