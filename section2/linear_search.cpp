#include<iostream>

struct Array{
    int A[20];
    int size;
    int length;
};
void swap(int *x,int*y){
    int temp=*x;
    *x=*y;
    *y=temp;

}
void display(const Array &arr){
        printf("The elements of the array are: \n");
        printf("[ ");
        for(int i{0};i<arr.length;i++){
            printf("%d ",arr.A[i]);
        }
        printf("] \n");
        
}

int Linear_search(Array *arr,int key){
    for (int i{0};sizeof(arr->A);i++){
        if (key==arr->A[i]){
            //transposition method
            // swap(&arr->A[i],&arr->A[i-1]);
            //move to head method
            // swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
        return -1; 
}

int main(){
    Array arr={{2,3,4,5,6},10,5};

    printf("%d \n",Linear_search(&arr,4));

    display(arr);


    return 0;

}