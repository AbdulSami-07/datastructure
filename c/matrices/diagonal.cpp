#include <iostream>

class Diagonal{
    private:
        int *A;
        int n;

    public:
        Diagonal(){
            this->n=2;
            this->A = new int[2];
        }
        Diagonal(int n){
            this->n = n;
            A = new int[n];
        }

        void set(int i, int j ,int x);
        int get(int i, int j);
        void display();
        ~Diagonal(){
            delete [] A;
        }
};



void Diagonal::set(int i,int j , int x){
    if(i==j)
        this->A[i-1] = x;
}

int Diagonal::get(int i, int j){
    if(i==j)
        return this->A[i-1];
    return 0;
}

void Diagonal::display(){
    for(int i = 0; i<this->n; i++){
        for (int  j = 0; j<this->n;j++){
            if(i==j)
                printf("%d ",this->A[i-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    Diagonal d = Diagonal(5);
    d.set(1,1,1);
    d.set(2,2,6);
    d.set(3,3,1);
    d.set(4,4,17);
    d.set(5,5,14);
    d.display();


}