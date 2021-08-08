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
int get(Array arr,int index){
    if (index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}
void set(Array &arr,int index,int x){
    if (index>=0 && index<arr.length){
        arr.A[index]=x;
    }
}
int Max(Array arr){
    int max=arr.A[0];
    for(int i{1};i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}
int Min(Array arr){
    int min=arr.A[0];
    for(int i{1};i<arr.length;i++){
        if(arr.A[i]<min){
           min=arr.A[i];
        }
    }
    return min;
}
int sum(Array arr){
    int s{0};
    int i{0};
    for(;i<arr.length;i++){
        s+=arr.A[i];
    }
    return s;
}

float Avg(Array arr){
    return (float)sum(arr)/arr.length;
}
int main(){
    Array arr={{2,3,4,5,6},10,5};

    printf("%d \n",Binary_Search(arr,5));
    printf("%d \n",R_Binary_Search(arr.A,0,arr.length,5));
    printf("the sum of array is %d \n",sum(arr));
    display(arr);


    return 0;
}