#include <stdio.h>

//Iterative
int fibi(int n) {
    if (n<=1)
        return n;
    int a = 0 , b = 1 , s = 0;
    for(int i =2; i<=n; i++){
       s = b + a;
       a = b;
       b = s;
    }
    return b;
}

int F[20];
int fib(int n) {
    if (n<=1) {
        F[n] = n;
        return F[n];
    }
    else{
        if (F[n-2] == -1)
            F[n-2] = fib(n-2);
        if (F[n-1] == -1)
            F[n-1] = fib(n-1);
        return F[n-2] + F[n-1];
    }
}

int main() {
    int n = 5;
   int  r1 = fibi(n);
   for (int i = 0; i< n; i++){
       F[i] = -1;
   }
   int r2 = fib(n);
   if (r1 == r2){
       printf("True %d",r1);
   }
   else
        printf("False %d %d",r1,r2);
    return 0;

}
