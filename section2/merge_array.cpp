#include<iostream>
#include<vector>
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


Array *merge_array(Array *arr1,Array *arr2){
    int i{0};
    int j{0};
    int k{0};
    Array *arr3=new Array{{},20,arr1->length+arr2->length};
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;){
        arr3->A[k++]=arr1->A[i++];
    }
    for(;j<arr2->length;){
        arr3->A[k++]=arr1->A[j++];
    }
    return arr3;
}
std::vector<int> rotateLeft(int d, std::vector<int> arr) {
    std::vector<int> arr2(arr.size(),0);
    int size_arr=arr2.size();
    for(int i{0};i<size_arr;i++){
        if(i>=d){
        arr2[i-d]=arr[i];
        }
        else{
            arr2[i+size_arr-d]=arr[i];
        }
    }
    return arr2;
}
    
int main(){
    Array arr1={{2,6,10,15,25},10,5};
    Array arr2 ={{3,4,7,18,20},10,5};
    Array *arr3=merge_array(&arr1,&arr2);
    display(*arr3);
    std::vector<int>A{1,2,3,4,5};
    std::vector<int>B=rotateLeft(2,A);
    for(auto elem:B){
        std::cout<<elem<<" ";
    }
    return 0;

}