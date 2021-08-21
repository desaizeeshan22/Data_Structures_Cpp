#include <iostream>
void print(int (&arr)[3][4]){
    for(int i{0};i<3;i++){
        for(int j{0};j<4;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void print_B(int *arr[3]){
    for(int i{0};i<3;i++){
        for(int j{0};j<4;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void print_C(int **arr){
    for(int i{0};i<3;i++){
        for(int j{0};j<4;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};
    int *B[3];
    print(A);
    
    for(int a{0};a<3;a++){
        B[a]=new int [4];
    }
    print_B(B);
    int **C=new int *[3];

     for(int b{0};b<3;b++){
        C[b]=new int [4];
    }
    print_C(C);


    for(int b{0};b<3;b++){
        delete C[b];

    }
    delete []C;
    
    
    for(int a{0};a<3;a++){
        delete B[a];
    }
    

    return 0;
}