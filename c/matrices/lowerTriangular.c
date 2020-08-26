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
    if (i>=j){
        m->A[i*(i-1)/2 + (j-1)] = x;
    }
}

int Get(struct Matrix *m, int i , int j){
    if(i>=j)
        return m->A[i*(i-1)/2 + (j-1)];
    return 0;
}

void Display(struct Matrix *m){
    for (int i = 1 ; i<=m->n ; i++){
        for(int j = 1; j<=m->n; j++){
            if(i>=j)
                printf("%d ",m->A[i*(i-1)/2 + (j-1)]);
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
    m->A = (int *) malloc( (m->n)*(m->n + 1)/2 * sizeof(int));
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