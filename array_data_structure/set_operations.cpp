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
Array *Union(Array * arr1,Array *arr2){
        int i{0};
        int j{0};
        int k{0};
        Array *arr3=new Array{{},20,arr1->length+arr2->length};
        while(i<arr1->length && j<arr2->length){
            if(arr1->A[i]<arr2->A[j]){
                arr3->A[k++]=arr1->A[i++];
            }
            else if (arr2->A[j]<arr1->A[i]){
                arr3->A[k++]=arr2->A[j++];
            }
            else if(arr1->A[i]==arr2->A[j]){
                arr3->A[k++]=arr2->A[i++];
                j++;
            }
        }
        for(;i<arr1->length;i++){
            arr3->A[k++]=arr1->A[i];
        }
        for(;j<arr2->length;j++){
            arr3->A[k++]=arr1->A[j];
        }
        arr3->length=k;
        return arr3;
}

Array *intersection(Array * arr1,Array *arr2){
        int i{0};
        int j{0};
        int k{0};
        Array *arr3=new Array{{},20,arr1->length+arr2->length};
        while(i<arr1->length && j<arr2->length){
            if(arr1->A[i]<arr2->A[j]){
                i++;
            }
            else if (arr2->A[j]<arr1->A[i]){
                j++;
            }
            else if(arr1->A[i]==arr2->A[j]){
                arr3->A[k++]=arr2->A[i++];
                j++;
            }
        }
        arr3->length=k;
        return arr3;
}
Array *difference(Array * arr1,Array *arr2){
        int i{0};
        int j{0};
        int k{0};
        Array *arr3=new Array{{},20,arr1->length+arr2->length};
        while(i<arr1->length && j<arr2->length){
            if(arr1->A[i]<arr2->A[j]){
                arr3->A[k++]=arr1->A[i++];
            }
            else if (arr2->A[j]<arr1->A[i]){
               j++;
            }
            else if(arr1->A[i]==arr2->A[j]){
                i++;
                j++;
            }
        }
        for(;i<arr1->length;i++){
            arr3->A[k++]=arr1->A[i];
        }
        arr3->length=k;
        return arr3;
}
int main(){
    Array arr1={{2,6,10,15,25},10,5};
    Array arr2 ={{3,6,7,15,20},10,5};
    Array *arr3{Union(&arr1,&arr2)};
    display(*arr3);
    Array *arr4{intersection(&arr1,&arr2)};
    display(*arr4);
    Array *arr5{difference(&arr1,&arr2)};
    display(*arr5);


    return 0;
}