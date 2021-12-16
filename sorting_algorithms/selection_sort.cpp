#include <iostream>


void swap(int &x,int&y){
    int temp=x;
    x=y;
    y=temp;
}

void selection_sort(int A[],int n){
    for(int i{0};i<n-1;i++){
        int j=i,k=i;
        while(j<n){
            if (A[j]<A[k]){
                k=j;
            }
            j++;
        }
        swap(A[i],A[k]);
    }
}


int main(){
    int A[]={8,5,3,2};
    selection_sort(A,4);
    printf("[ ");
    for(auto elem:A){
        printf("%d,",elem);
    }
    printf("]");

    return 0;
}