#include <iostream>
/* 
We have consider matrix to start from 1, indeces.
Matrix as [nxn]
*/

using namespace std;

class LowerTriangular{
    private:
        int *A;
        int n;

    public:
        LowerTriangular(){
            this->n=2;
            this->A = new int[2*(2+1)/2];
        }
        LowerTriangular(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }

        void set(int i, int j ,int x);
        int get(int i, int j);
        void display();

        ~LowerTriangular(){
            delete [] A;
        }
};



void LowerTriangular::set(int i,int j , int x){
    if(i>=j) 
        this->A[i*(i-1)+j-1] = x;
}

int LowerTriangular::get(int i, int j){
    if(i>=j)
        return this->A[i*(i-1)+j-1];
    return 0;
}

void LowerTriangular::display(){
    for(int i = 1; i<=this->n; i++){
        for (int  j = 1; j<=this->n;j++){
            if(i>=j)
                printf("%d ",this->A[i*(i-1)+j-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    int d;
    cout << "Enter Dimension: ";
    cin>>d;

    LowerTriangular ltm = LowerTriangular(d);
    for (int i =1 ; i<=d ; i++)
        for (int j = 1 ; j<=d ; j++){
            int x;
            scanf("%d",&x);
            ltm.set(i,j,x);
        }
    printf("\n\n");
    ltm.display();


}