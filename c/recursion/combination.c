#include <stdio.h>

int nCr(int n , int r){
    if ( r==0 || n==r)
        return 1;
    else 
        return nCr(n-1,r-1) + nCr(n-1,r);
}

int main() {
    int  n = 4 , r = 3;
    printf("%d",nCr(4,3));
}
