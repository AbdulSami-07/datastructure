#include <stdio.h>
#include <stdlib.h>
/*
Using row major.  
*/
struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i , int j ,int x){
    if (i-j == 1)
        m->A[i-1] =x;
    else if (i-j == 0)
        m->A[m->n-1 + i-1] = x;
    else if (i-j == -1)
        m->A[2*m->n-1 + i-1] = x;
}

int Get(struct Matrix *m, int i , int j){
    if (i-j == 1)
        return m->A[i-1];
    else if (i-j == 0)
        return m->A[m->n-1 + i-1];
    else if (i-j == -1)
        return m->A[2*m->n-1 + i-1];
}

void Display(struct Matrix *m){
    for (int i = 1 ; i<=m->n ; i++){
        for(int j = 1; j<=m->n; j++){
            if (i-j == 1)
                printf("%d ",m->A[i-1]);
            else if (i-j == 0)
                printf("%d ",m->A[m->n-1 + i-1]);
            else if (i-j == -1)
                printf("%d ",m->A[2*m->n-1 + i-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}


int main(){
    struct Matrix *m;
    printf("Enter Dimension: ");
    scanf("%d",&m->n);
    m->A = (int *) malloc( (3*m->n -2) * sizeof(int));
    // Set(&m,1,1,5);Set(&m,2,1,2);Set(&m,3,1,7);Set(&m,2,2,10);Set(&m,2,3,17);Set(&m,3,3,10);
    for (int i = 1; i<= m->n; i++)
        for(int j = 1 ; j<=m->n;j++){
            int x;
            scanf("%d",&x);
            Set(m,i,j,x);
        }

    printf("\n\n");
    Display(m);


}