#include<iostream>

struct Array{
    int A[20];
    int size;
    int length;
};

int Binary_Search(Array arr,int key){
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid]){
             return mid;
         }
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
        
    }
    return -1;

}
int R_Binary_Search(int A[],int l,int h,int key){
    if(l<=h){
        int mid=(l+h)/2;
        if(key==A[mid]){
             return mid;
         }
        else if(key<A[mid]){
            return R_Binary_Search(A,l,mid-1,key);
        }
        else{
            return R_Binary_Search(A,mid+1,h,key);
        }
    }
    return -1;
}
void display(const Array &arr){
        printf("The elements of the array are: \n");
        printf("[ ");
        for(int i{0};i<arr.length;i++){
            printf("%d ",arr.A[i]);
        }
        printf("] \n");
        
}

int main(){
    Array arr={{2,3,4,5,6},10,5};

    printf("%d \n",Binary_Search(arr,4));

    display(arr);


    return 0;
}