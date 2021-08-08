#include<iostream>

struct Array{
    int A[20];
    int size;
    int length;
};

void display(const Array &arr){
        printf("The elements of the array are: \n");
        printf("[ ");
        for(int i{0};i<arr.length;i++){
            printf("%d ",arr.A[i]);
        }
        printf("] \n");
        
}

void reverse_array(Array &arr){
    int B[arr.length];
    for(int i{arr.length-1},j{0};i>=0;i--,j++){
        B[j]=arr.A[i];
    }
    for(int i{0};i<arr.length;i++){
        arr.A[i]=B[i];
    }

}
int main(){
    Array arr={{2,3,4,5,6},10,5};
    display(arr);
    printf("\n");
    reverse_array(arr);
    display(arr);
}