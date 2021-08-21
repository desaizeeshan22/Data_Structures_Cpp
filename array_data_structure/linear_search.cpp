#include<iostream>
#include<vector>
#include <iomanip>
#include <iostream>
#include <map>
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
    for (int i{0};i<sizeof(arr->A);i++){
        if (key==arr->A[i]){
            //transposition method
            swap(&arr->A[i],&arr->A[i-1]);
            //move to head method
            // swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
        return -1; 
}
#include <algorithm>
std::vector<int> solution(std::vector<int> &A) {
    int sum{0};
    std::vector<int>row_sum(0,3);
    std::vector<int>col_sum(0,3);
    for(int j{0};j<3;j++){
        sum=0;
        for(int k{0};k<3;k++){
            sum+=A[3*j+k];
    }
    row_sum.push_back(sum);
    }
    int max_sum=*std::max_element(row_sum.begin(),row_sum.end());
    for(int i{0},j{2};i<3;i++,j--){
        A[3*i+j]=max_sum-row_sum[i];
    }
    return A;
}
void display_vec(const std::vector<int> &arr){
        printf("The elements of the vector are: \n");
        printf("[ ");
        for(auto elem:arr){
            printf("%d ",elem);
        }
        printf("] \n");
        
}
  

int main(){
    // Array arr={{2,3,4,5,6},10,5};

    // printf("%d \n",Linear_search(&arr,4));

    // display(arr);
    std::vector<int>A{0, 2, 3, 4, 1, 1, 1, 3, 1};
    display_vec(solution(A));
   


    return 0;

}