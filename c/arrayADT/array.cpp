#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Array{
    private:
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);

    public:
        Array(){
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz){
            size = sz;
            length =0;
            A = new int[size];
        }
        ~Array(){
            delete []A;
        }


void Display();
void Insert( int index , int x);
void Append(int x);
int Delete(int index);
int BinarySearch(int low , int high , int x);
int Get(int index);
void Set(int index, int value);
int Max();
int Min();
int Sum();
int Avg();
void Reverse();
void LeftShift();
void RightShift();
void RotateLeft();
void RotateRight();
void InsertInSorted();
int IsSorted();
void NegativeOnLeft(struct Array *arr);
Array * Merge(Array *arr2);
Array *Union(Array *B);
Array *Intersection(Array *arr2);
Array *Difference(Array *arr2);
int SetMembership(Array *arr, int x);

void Array::Display(){
    int i ;
    puts("\n");
    for (i = 0 ; i<length; i++){
        printf("%d ",A[i]);
    }
    puts("\n");
}

void Array::Insert(int index , int x){
    int i;
    if (index>=0 && index <=length){
        for (i=length; i>index; i--){
           A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

void Array::Append(int x){
    if (length < size)
        A[length++] =  x;
}

int Array::Delete(int index){
    int i;
    int x = 0;
    if (index>=0 && index <length){
        x = A[index];
        for (i = index ; i< length - 1; i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return x;
}

void Array::swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int Array::BinarySearch( int low , int high , int x) {
    int mid;
    while (low<=high){
        mid = floor((low+high)/2);
        if (x == A[mid])
            return mid;
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Array::Get(int index){
    if ( index >=0 && index <= length){
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int value){
    if ( index >=0 && index <= length){
        A[index] = value;
    }
}

int Array::Max(){
    int max = A[0];
    for (int i = 1 ;  i<length; i++){
        if (max < A[i])
            max = A[i];
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for (int i = 1 ;  i < length; i++){
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum(){
    int sum = 0;
    for (int i = 0; i<length; i++)
        sum += A[i];
    return sum;
}

int Array::Avg(){
    return Sum()/length;
}

void Array::Reverse(){
    int i, j;
    for (i = 0, j = length -1; i<j; i++,j--){
        swap(&A[i],&A[j]);
    }
}

void Array::LeftShift(){
    for(int i = 0; i < length -1 ; i++){
        swap(&A[i],&A[i+1]);
    }
    A[length-1] = 0;
}

void Array::RightShift(){
    for(int i = length-1; i>0; i--){
        swap(&A[i-1],&A[i]);
    }
    A[0] = 0;
}

void Array::RotateLeft(){
    int temp = A[0];
    for(int i = 0; i < length -1 ; i++){
        swap(&A[i],&A[i+1]);
    }
    A[length-1] = temp;
}

void Array::RotateRight(){
    int temp =A[length-1];
    for(int i = length-1; i>0; i--){
        swap(&A[i-1],&A[i]);
    }
   A[0] = temp;
}

void Array::InsertInSorted(int x){
    Append(x);
    if(A[length-1] == x){
        int i = length - 1;
        while (A[i-1] > A[i] && i>0){
            swap(&A[i-1],&A[i]);
            i--;
        }
    }
}

int Array::IsSorted(struct Array *arr){
    int i = 0;
    while (i<length-1)
        if (A[i] >A[i+1])
            return 0;
        else
            i++;
    return 1;
}

void Array::NegativeOnLeft(){
    int i = 0;
    int j = length-1;
    while(i<j){
        while(A[i]<0)
            i++;
        while(A[j]>0)
            j--;
        if(i<j)
            swap(&A[i],&A[j]);
    }
}

Array * Array::Merge(Array *arr2){
    Array *arr3 = new Array();
    arr3->length = length + arr2->length;
    if(arr3){
        size = 10;
        int i = 0;
        int j = 0;
        int k = 0;
        while (i<length && j < arr2->length){
            if (A[i] < arr2->A[j]){
                arr3->A[k] = A[i];
                i++;
                k++;
            }
            else{
                arr3->A[k] = arr2->A[j];
                j++;
                k++;
            }
        }
        for (; i<length;i++)
            arr3->A[k++] = A[i];
        for (; j<arr2->length;j++)
            arr3->A[k++] = arr2->A[j];
    }
    return arr3;
}

Array * Array::Union(Array *B){
    Array *C = new Array();
    int i,j,k;
    i=j=k=0;
    if(C){
    while (i <length && j < B->length){
        if (A[i]<B->A[j])
            C->A[k++] = A[i++];
        else if (A[i]>B->A[j])
            C->A[k++]  = B->A[j++];
        else if (A[i] == B->A[j]) {
            C->A[k++] = A[i++];
            j++;
        }
    }
    for (;i<length;)
        C->A[k++] = A[i++];
    for (;j<B->length;)
        C->A[k++] = B->A[j++];
    C->length = k;
    return C;
    }
    return NULL;

}

Array * Array::Intersection(Array *arr2){
    Array *arr3 = new Array();
    if (arr3){
        int i,j,k;
        i=j=k=0;
        while(i < length && j < arr2->length){
            if(A[i] == arr2->A[j]){
                arr3->A[k++] = A[i];
                j++;
            }
            else if(A[i]< arr2->A[j])
                i++;
            else
                j++;
        }
        arr3 -> length = k;
        return arr3;
    }

    return  NULL;
}

Array * Array::Difference( Array *arr2){
    Array *arr3 = new Array();
    if (arr3){
        int i,j,k;
        i=j=k=0;
        while(i <length && j < arr2->length){
            if (A[i] < arr2->A[j])
                arr3->A[k++] = A[i++];
            else if (arr2->A[j] < A[i])
                j++;
            else{
                i++;
                j++;
            }
        }
        for(;i <length;)
            arr3->A[k++] = A[i++];
        arr3->length = k;
        return arr3;
    }
    return NULL;
}

int Array::SetMembership( int x){
    return BinarySearch(0, length - 1,x);
}

};


int main() {
    struct Array arr;

}