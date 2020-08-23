#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p , *q;
    p = (int *) malloc(5*sizeof(int));
    for (int i  = 0; i < 5; i++){
        p[i] = i;
    }
    q = (int *) malloc(10*sizeof(int));
    for (int i= 0; i< 5; i++){
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;
    for(int i = 5; i < 10 ; i++){
        p[i] = i;
    }
    for (int i = 0 ; i<10;i++){
        printf("%d ",p[i]);
    }
    puts("\n");
    return 0;
}