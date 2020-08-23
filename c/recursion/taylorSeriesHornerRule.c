#include <stdio.h>

// Recursive Approach.
double e(int x, int n) {
    static double s = 1;
    if (n==0)
        return s;
    else {
        s = 1 + (double) x/n*s;
        return e(x,n-1);
    }
}

//Iterative Approach
double ei(int x , int n){
    double s = 1;
    for (;n>0;n--){
        s = 1 + (double) x/n*s;
    }
    return s;
}

int main() {
    int x = 1 , n = 10;
   double  r1 = e(x,n);
   double  r2 = ei(x,n);
   printf("%f %f ",r1,r2);
}

