#include <iostream>


void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}

void Bubble_sort(int A[],int n){
    for(int i{0};i<n-1;i++){
        for(int j{0};j<n-i;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
            }
        }
    }
}

int main(){

    int A[]={8,5,7,3,2};
    Bubble_sort(A,5);
    printf("[ ");
    for (auto elem:A){
        
        printf("%d ",elem);
    }
    printf(" ] ");
    return 0;
    
}