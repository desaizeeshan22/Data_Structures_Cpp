#include<iostream>
#include<memory>
struct Array{
    int *ptr;
    int size;
    int length;
};

void display(const Array &arr){
        printf("The elements of the array are: \n");
        printf("[ ");
        for(int i{0};i<arr.length;i++){
            printf("%d ",arr.ptr[i]);
        }
        printf("] \n");
        
}
void append(Array *arr,int x){
    if(arr->length<arr->size){
        
        arr->ptr[arr->length++]=x;
    }
}
void insert(Array &arr,int index,int element){
    for(int i{arr.length};i>index;i--){
        arr.ptr[i]=arr.ptr[i-1];
    }
    arr.ptr[index]=element;
    arr.length++;
}

void Delete(Array &arr,int index){
    for(int i{index};i<arr.length-1;i++){
        arr.ptr[i]=arr.ptr[i+1];
    }
    arr.length--;
}
int main(){
    Array arr;
    printf("Enter size of an array :");

    scanf("%d",&arr.size);
    arr.ptr=new int [arr.size];
    int n{0};
    printf("Enter the number of numbers : ");
    scanf("%d",&n);
    printf("Enter all elements of an array \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr.ptr[i]);
    }
    arr.length=n;
    append(&arr,69);
    insert(arr,2,4);
    display(arr);
    // int largest=arr.ptr[0];
    // for(int i{1};i<arr.length;i++){
    //     if(arr.ptr[i]>largest){
    //         largest=arr.ptr[i];
    //     }

    // }
    // printf("%d ",largest);
    return 0;



}