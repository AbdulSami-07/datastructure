#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Array{
    int A[10]; //change to *A
    int size;
    int length;
};

void Display(struct Array arr);
void Insert(struct Array *arr, int index , int x);
void Append(struct Array *arr,int x);
int Delete(struct Array *arr, int index);
int LinearSearch(struct Array *arr, int x);
void swap(int *x, int *y);
int LinearSearchTransposition(struct Array *arr, int x);
int LinearSearchMoveToFirst(struct Array *arr, int x);
int BinarySearch(struct Array *arr, int low, int high, int x);
int BinarySearchIter(struct Array *arr, int low , int high , int x);
int Get(struct Array *arr, int index);
void Set(struct Array *arr, int index, int value);
int Max(struct Array *arr);
int Min(struct Array *arr);
int Sum(struct Array *arr);
int Avg(struct Array *arr);
void Reverse(struct Array *arr);
void LeftShift(struct Array *arr);
void RightShift(struct Array *arr);
void RotateLeft(struct Array *arr);
void RotateRight(struct Array *arr);
void InsertInSorted(struct Array *arr, int x);
int IsSorted(struct Array *arr);
void NegativeOnLeft(struct Array *arr);
struct Array * Merge(struct Array *arr1, struct Array *arr2);
struct Array *Union(struct Array *A, struct Array *B);
struct Array *Intersection(struct Array * arr1, struct Array *arr2);
struct Array *Difference(struct Array * arr1, struct Array *arr2);
int SetMembership(struct Array *arr, int x);
struct Array * MissingElements(struct Array *arr);

void Display(struct Array arr){
    int i ;
    puts("\n");
    for (i = 0 ; i<arr.length; i++){
        printf("%d ",arr.A[i]);
    }
    puts("\n");
}

void Insert(struct Array *arr, int index , int x){
    int i;
    if (index>=0 && index <= arr->length){
        for (i=arr->length; i>index; i--){
            arr-> A[i] = arr-> A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

void Append(struct Array *arr,int x){
    if (arr->length < arr->size)
        arr->A[arr->length++] =  x;
}

int Delete(struct Array *arr, int index){
    int i;
    int x = 0;
    if (index>=0 && index < arr->length){
        x = arr->A[index];
        for (i = index ; i< arr->length - 1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return x;
}

int LinearSearch(struct Array *arr, int x){
    int i ;
    for(i=0; i<= arr->length; i++){
        if(arr->A[i] == x)
            return i;
    }
    return -1;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearchTransposition(struct Array *arr, int x) {
    int i ;
    for(i=0; i<= arr->length; i++){
        if(arr->A[i] == x){
            if(i > 0){
            swap(&arr->A[i],&arr->A[i-1]);
            return i -1;
            }else {
                return i ;
            }
        
        }
    }
    return -1;
}

int LinearSearchMoveToFirst(struct Array *arr, int x) {
    int i ;
    for(i=0; i<= arr->length; i++){
        if(arr->A[i] == x){
            swap(&arr->A[i],&arr->A[0]);
            return 0;
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr, int low, int high, int x) {
    if(high - low < 0)
        return -1;
    int mid = floor((low+high)/2);
    if (arr->A[mid] == x )
        return mid;
    else if (x < arr->A[mid])
        return BinarySearch(arr,low,mid-1,x);
    else
        return BinarySearch(arr,mid+1,high,x);
}

int BinarySearchIter(struct Array *arr, int low , int high , int x) {
    int mid;
    while (low<=high){
        mid = floor((low+high)/2);
        if (x == arr->A[mid])
            return mid;
        else if (x < arr->A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Get(struct Array *arr, int index){
    if ( index >=0 && index <= arr->length){
        return arr->A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int value){
    if ( index >=0 && index <= arr->length){
        arr->A[index] = value;
    }
}

int Max(struct Array *arr){
    int max = arr->A[0];
    for (int i = 1 ;  i<arr->length; i++){
        if (max < arr->A[i])
            max = arr->A[i];
    }
    return max;
}

int Min(struct Array *arr){
    int min = arr->A[0];
    for (int i = 1 ;  i < arr->length; i++){
        if (arr->A[i] < min)
            min = arr->A[i];
    }
    return min;
}

int Sum(struct Array *arr){
    int sum = 0;
    for (int i = 0; i<arr->length; i++)
        sum += arr->A[i];
    return sum;
}

int Avg(struct Array *arr){
    return Sum(arr)/arr->length;
}

void Reverse(struct Array *arr){
    int i, j;
    for (i = 0, j = arr->length -1; i<j; i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

void LeftShift(struct Array *arr){
    for(int i = 0; i < arr->length -1 ; i++){
        swap(&arr->A[i],&arr->A[i+1]);
    }
    arr->A[arr->length-1] = 0;
}

void RightShift(struct Array *arr){
    for(int i = arr->length-1; i>0; i--){
        swap(&arr->A[i-1],&arr->A[i]);
    }
    arr->A[0] = 0;
}

void RotateLeft(struct Array *arr){
    int temp = arr->A[0];
    for(int i = 0; i < arr->length -1 ; i++){
        swap(&arr->A[i],&arr->A[i+1]);
    }
    arr->A[arr->length-1] = temp;
}

void RotateRight(struct Array *arr){
    int temp = arr->A[arr->length-1];
    for(int i = arr->length-1; i>0; i--){
        swap(&arr->A[i-1],&arr->A[i]);
    }
    arr->A[0] = temp;
}

void InsertInSorted(struct Array *arr, int x){
    Append(arr,x);
    if(arr->A[arr->length-1] == x){
        int i = arr->length - 1;
        while (arr->A[i-1] > arr->A[i] && i>0){
            swap(&arr->A[i-1],&arr->A[i]);
            i--;
        }
    }
}

int IsSorted(struct Array *arr){
    int i = 0;
    while (i<arr->length-1)
        if (arr->A[i] > arr->A[i+1])
            return 0;
        else
            i++;
    return 1;
}

void NegativeOnLeft(struct Array *arr){
    int i = 0;
    int j = arr->length-1;
    while(i<j){
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>0)
            j--;
        if(i<j)
            swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array * Merge(struct Array *arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    if(arr3){
        arr3->size = 10;
        arr3->length = arr1->length + arr2->length;
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < arr1->length && j < arr2->length){
            if (arr1->A[i] < arr2->A[j]){
                arr3->A[k] = arr1->A[i];
                i++;
                k++;
            }
            else{
                arr3->A[k] = arr2->A[j];
                j++;
                k++;
            }
        }
        for (; i<arr1->length;i++)
            arr3->A[k++] = arr1->A[i];
        for (; j<arr2->length;j++)
            arr3->A[k++] = arr1->A[j];
    }
    return arr3;
}

struct Array *Union(struct Array *A, struct Array *B){
    struct Array *C = (struct Array *) malloc(sizeof(struct Array));
    int i,j,k;
    i=j=k=0;
    if(C){
    while (i < A->length && j < B->length){
        if (A->A[i]<B->A[j])
            C->A[k++] = A->A[i++];
        else if (A->A[i]>B->A[j])
            C->A[k++]  = B->A[j++];
        else if (A->A[i] == B->A[j]) {
            C->A[k++] = A->A[i++];
            j++;
        }
    }
    for (;i<A->length;)
        C->A[k++] = A->A[i++];
    for (;j<B->length;)
        C->A[k++] = B->A[j++];
    C->length = k;
    return C;
    }
    return NULL;

}

struct Array *Intersection(struct Array * arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    if (arr3){
        int i,j,k;
        i=j=k=0;
        while(i < arr1->length && j < arr2->length){
            if(arr1->A[i] == arr2->A[j]){
                arr3->A[k++] = arr1->A[i];
                j++;
            }
            else if(arr1->A[i]< arr2->A[j])
                i++;
            else
                j++;
        }
        arr3 -> length = k;
        return arr3;
    }

    return (struct Array *) NULL;
}

struct Array *Difference(struct Array * arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    if (arr3){
        int i,j,k;
        i=j=k=0;
        while(i < arr1->length && j < arr2->length){
            if (arr1->A[i] < arr2->A[j])
                arr3->A[k++] = arr1->A[i++];
            else if (arr2->A[j] < arr1->A[i])
                j++;
            else{
                i++;
                j++;
            }
        }
        for(;i < arr1->length;)
            arr3->A[k++] = arr1->A[i++];
        arr3->length = k;
        return arr3;
    }
    return NULL;
}

int SetMembership(struct Array *arr, int x){
    return BinarySearch(arr,0, arr->length - 1,x);
}

struct Array * FindMissingElementsInSorted(struct Array *arr){
    int diff = arr->A[0] - 0;
    struct Array *r = (struct Array *) malloc(sizeof(struct Array));
    int i = 1;
    int k =0;
    while(i<arr->length){
        if (arr->A[i]-i != diff){
           r->A[k++] = diff + i;
           r->length++;
        }
        i++;
    }
    return r;
}

struct Array *FindDuplicateInSorted(struct Array *arr){
    struct Array *r = (struct Array * ) malloc(sizeof(struct Array));
    int diff = arr->A[0] - 0;
    int i = 1;
    int k = 0;
    while (i<arr->length){
        if (arr->A[i-1] == arr->A[i]){
            r->A[k++] = arr->A[i];
            r->length++;
        }
        i++;
    }
    return r;
}

int * FindPairsWithSumK(struct Array *arr,int k){
    int *A = (int *) malloc(((int) k/2) * sizeof(int));
    int p = 0;
    for (int i = 0; i<arr->length;i++){
        int a = arr->A[i];
        for (int j = i+1; j<arr->length ;j++){
            if (arr->A[j] == (k-a) ){
                A[p++] = a;
                A[p++] = arr->A[j];
            }
        }
    }
    return A;
}

void FindMissingElementsInUnsorted(struct Array *arr, int min, int max){
    struct Array *H= (struct Array *) malloc(sizeof(struct Array));
    H->length = max;
    for (int i=0 ; i<arr->length;i++){
        H->A[arr->A[i]]++;
    }
    for(int i = min ; i<=max; i++){
        if(H->A[i] == 0)
            printf("%d ",i);
    }
    printf("\n");

}

void FindDuplicateInUnsorted(struct Array *arr){
    for (int i = 0; i<arr->length; i++){
        int count = 1;
        if(arr->A[i] != -1){
            for (int j = i+ 1; j<arr->length;j++){
                if (arr->A[i] == arr->A[j]){
                    count++;
                    arr->A[j] == -1;
                }
            
            }
            printf("(%d,%d) ",arr->A[i], count);
        }
    }
    printf("\n");
}





int main() {
    struct Array arr = {{1,2,3,2},10,4};
    FindDuplicateInUnsorted(&arr);
}