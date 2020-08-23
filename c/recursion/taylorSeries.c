#include <stdio.h>
#include <math.h>

double taylor(int x , int n) {
    static double  p = 1 , f = 1;
    double r;
    if (n == 0) 
        return 1;
    else {
        r  = taylor(x,n-1);
        p = p*x;
        f = f*n;
        return (r + p/f) ;
    }
}

int main() {
    int x = 4 , n = 20 ;
    double r = taylor(x,n);
    printf("%f",r);
    return 0;
}