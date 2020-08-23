#include <stdio.h>
#include <string.h>

int Length(char *str){
    int i  = 0;
    while (str[i++] != '\0');
    return i-1;
}

void ToUpper(char str[]){
    for (int i =0 ; str[i]!='\0';i++){
        if (str[i]>=97 && str[i]<= 122){
            str[i] -= 32;
        }
    }
}

void FindDuplicateInSmallCase(char str[]){
    int H = 0;
    for (int i = 0; str[i]!='\0'; i++){
        int x = 1;
        x = x<<str[i]-97;
        if( (H & x) > 0){
            printf("%c",str[i]);
        }
        else
        {
            H = x | H;
        }
    }
    printf("\n");
}

int Anagram(char a[],char b[]){ //Assume string Lengths are equal. and are small cased. 
    int H[26] = {0};
    for (int i = 0 ; a[i]!= '\0' ; i++){
        H[a[i]-97]++;
    }
    for(int i = 0; b[i]!='\0';i++){
        if(--H[b[i]-97] == -1)
            return -1;
    }
    for (int i = 0; i<26;i++)
        if(H[i]>=1)
            return -1;
    return 1;
}

void Permutation(char a[],char r[],int f[],int k){
    /* a is string,
        b is char array of size equal to a,
        f is array initialized to 0 with size equal to len(a)-1,
        k is initialized to 0.
    */

    if(a[k] == '\0'){
        r[k] = '\0';
        printf("%s ",r);
    }
    else{
        for(int i = 0; a[i]!='\0';i++ ){
            if(f[i] == 0){
                f[i] = 1;
                r[k] = a[i];
                Permutation(a,r,f,k+1);
                f[i] = 0;
            }
        }
    }
}

void Permutation2(char a[],int k){
    static int f[10] = {0};
    static char r[10];
    if(a[k] == '\0'){
        r[k] = '\0';
        printf("%s ",r);
    }

    for (int i = 0; a[i]!='\0'; i++){
        if(f[i] == 0){
            f[i] = 1;
            r[k] =a[i];
            Permutation2(a,k+1);
            f[i] = 0;
        }
    }
}

void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void PermutationUsingSwap(char a[],int l,int h){ // h = last index of a
    if (l == h){
        printf("%s ",a);
    }
    else{
        for (int i = l; i<=h ;i++){
            swap(&a[i],&a[l]);
            PermutationUsingSwap(a,l+1,h);
            swap(&a[i],&a[l]);
        }
    }
}

int main (){
    char a[] ="abcd";
    PermutationUsingSwap(a,0,3);
    printf("\n");

}