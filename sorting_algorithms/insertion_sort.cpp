#include <iostream>

void swap(int &x,int&y){
    int temp=x;
    x=y;
    y=temp;
}
void insertion_sort(int A[],int n){
    for(int i{1};i<n;i++){
        for (int j{0};j<i;j++){
            while(A[j]>A[i]){
                swap(A[i],A[j]);
            }
        }
    }
}


int main(){
    int A[]={8,5,3,2};
    insertion_sort(A,4);
    printf("[ ");
    for(auto elem:A){
        printf("%d,",elem);
    }
    printf("]");

    return 0;
}