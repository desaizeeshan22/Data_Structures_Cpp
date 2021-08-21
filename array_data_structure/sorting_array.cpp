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

void insert_sort(Array &arr,int x){
    if(arr.size==arr.length){
        return ;
    }
    int i{arr.length-1};
    while(i>=0 &&arr.A[i]>x){
        arr.A[i+1]=arr.A[i];
        i--;
    }
    arr.A[i+1]=x;
    arr.length++;

}
int is_sorted(const Array &arr){
    for(int i{0};i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}
void swap(int *x,int*y){
    int temp=*x;
    *x=*y;
    *y=temp;

}

void rearrange(Array *arr){
    int i{0},j{arr->length-1};
    while(i<j){
        while(arr->A[i]<0){
            i++;
        }
        while(arr->A[j]>=0){
            j--;
        }
        if(i<j){
        swap(&arr->A[i],&arr->A[j]);
        }


    }
}

int main(){
    Array arr={{2,3,5,10,15},10,5};
    Array arr_2={{2,-3,5,-10,-15,25},10,6};
    insert_sort(arr,1);
    rearrange(&arr_2);
    display(arr);
    display(arr_2);
}