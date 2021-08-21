#include <iostream>

struct Matrix{
    int A[10];
    int n;

};

void Set( Matrix &m,int i,int j,int x){
    if(i==j){
        m.A[i-1]=x;
    }
}
int Get(Matrix m,int i,int j){
    if(i==j){
        return m.A[i-1];
    }
    else{
        return 0;
    }
}

void Display(const Matrix &m){
    for(int i{0};i<m.n;i++){
        for(int j{0};j<m.n;j++){
            if(i==j){
                printf("%d ",m.A[i]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){

    Matrix m;
    m.n=4;
    Set(m,1,1,5);
    Set(m,2,2,8);
    Set(m,3,3,9);
    Set(m,4,4,12);
    Display(m);
    return 0;
}

